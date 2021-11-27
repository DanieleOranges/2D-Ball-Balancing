function [fval,results] = OpenEndOptimalControl(tf)

%% Initial and final time
t0 = 0;                     % Initial time [s]
tf = 10;
N  = 200;                   % Number of spacesteps/timesteps [~]
h = tf/(N-1);               % Temporal discretization [s]
t = t0:h:N*h;                % Time array [s]

%% Reference generation
ref = load('Monza.mat');
% ref = load('Skidpad.mat');
p = interparc(N+1,ref.x,ref.y); ref.x = p(:,1); % Arclength interpolation
                                ref.y = p(:,2); clear p

xref   = [zeros(N+1,1),ref.x,zeros(N+1,1),ref.y]';

%% Boundary conditions on initial and final states
% Initial States x_i = [xp,x,yp,y]|i
x_i = xref(:,1);
% Final States x_f = [xp,x,yp,y]|f
x_f = xref(:,end);
 
%% Mechanical System definition
[dx,fx,fu] = mechSystem();
nx = 4;          % Number of states
nu = 2;          % Number of inputs

%% Functional Weights definition

% Time Cost
T = 0.001;

% Control Cost
R = [ 0.1,     0;
        0,   0.1];

% State Cost
Q = [ 0,  0,  0,  0;
      0, 10,  0,  0;
      0,  0,  0,  0;
      0,  0,  0, 10];

% Final State Cost
P = [ 0,  0,  0,  0; 
      0, 10,  0,  0;
      0,  0,  0,  0;
      0,  0,  0, 10];

% Cost Function
L = @(x,u,xref) 0.5*(x-xref)'*Q*(x-xref) + 0.5*u'*R*u + T*(tf-t0) ; % Running cost
p = @(x) 0.5*(x - x_f)'*P*(x - x_f) ;                               % Final cost

% Cost function partial derivatives
Lx =@(x,u,xref) Q*(x - xref);
Lu =@(x,u) R'*u;
px =@(x)   P*(x - xref(:,end));

%% Setup minimization problem

% Options
options = optimoptions('fmincon', ...
                       'MaxFunctionEvaluations',1.5e+04, ...
                       'SpecifyObjectiveGradient',false, ...
                       'SpecifyConstraintGradient',true, ...
                       'CheckGradients',true, ...
                       'Display','final');

% Initial Condition z0
z0 = zeros(N*(nx + nu) + nx,1);

% ~~~~~~~~~~~~~~~~~~~~~~ Optimization Parameters~~~~~~~~~~~~~~~~~~~~~~~~ %

parameters()

% ~~~~~~~~~~~~~~~~~~~~~~ Constraint and OF ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ %

ObjFun = @(z) cost_and_grad(z,param);
NLcon = @(z) con_and_grad(z,param);

% Maximum error on state reference and control action
max_errx = 0.05;       % [m]
max_errv = 100;        % [m/s]
max_u    = 90/180*pi;  % [rad]
[lb,ub] = bound_define(xref,max_errx,max_errv,max_u,nx,nu,N);

% linear inequalities
A = [];
b = [];
Aeq = [];
beq = []; 

% Minimize ObjFun s.t. NLcon
[z,fval,exitflag,output,lambda] = fmincon(ObjFun,z0,A,b,Aeq,beq,lb,ub,NLcon,options);

%% State and control extraction from z

x = zeros(nx,N+1); u = zeros(nu,N);
for ii = 0:N
    x(:,ii+1) = z((1 + ii*(nu + nx)):(nx + ii*(nu + nx)));             % [m/s;m;m/s,m]
end    
for ii = 0:N-1
    u(:,ii+1) = z((1 + nx + ii*(nu + nx)):(nx + nu + ii*(nu + nx)));   % [~] 
end

results.x = x;
results.u = u;
results.time = t;
results.xref = xref;

end
    