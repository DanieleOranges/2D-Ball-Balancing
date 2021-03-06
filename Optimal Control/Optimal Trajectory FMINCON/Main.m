%% Intro
clear 
close all
clc
set(0,'DefaultFigureWindowStyle','docked')

% ~~~~~~~~~~~~~~~~~~~~~~~~~ COSE DA FARE ANCORA ~~~~~~~~~~~~~~~~~~~~~~~~~ %
% - Dinamica più precisa
% - Funzionale corretto
% - Constraint sui bound del controllo
% - Possibilità di aggiungere la minimizzazione della potenza elettrica come 
%   constraint non lineare in controllo e stato
% - Constraint sul gradiente del controllo (u deve essere C1)

%% Initial and final time
t0 = 0;                     % Initial time [s]
tf = 10;                    % Final time [s]

% % Timestep Control
% h  = 0.1;                 % Temporal discretization [s]
% N  = tf/h +1;             % Number of spacesteps/timesteps [~]

% Dimension Control
N  = 300;                   % Number of spacesteps/timesteps [~]
h  = tf/(N-1);              % Temporal discretization [s]

t  = 0:h:N*h;               % Time array [s]

%% Reference generation
targetpath = strcat(fileparts(pwd),'\Piste/');
[trackname,~] = uigetfile(targetpath,'Select Track');
ref = load(strcat(targetpath,trackname));

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
% Control Cost
R = [ 0.1,     0;
        0,   0.1];

% State Cost
Q = [ 0,  0,  0,  0;
      0,  1,  0,  0;
      0,  0,  0,  0;
      0,  0,  0,  1];

% Final State Cost
P = [ 0,  0,  0,  0; 
      0, 10,  0,  0;
      0,  0,  0,  0;
      0,  0,  0, 10];

% Cost Function
L = @(x,u,xref) 0.5*(x-xref)'*Q*(x-xref) + 0.5*u'*R*u  ; % Running cost
p = @(x) 0.5*(x - x_f)'*P*(x - x_f) ;                    % Final cost

% Cost function partial derivatives
Lx =@(x,u,xref) Q*(x - xref);
Lu =@(x,u)      R'*u;
px =@(x)        P*(x - xref(:,end));

%% Setup minimization problem

% Options
options = optimoptions('fmincon', ...
                       'Algorithm','interior-point', ...
                       'MaxFunctionEvaluations',1e+04, ...
                       'SpecifyObjectiveGradient',false, ...
                       'SpecifyConstraintGradient',false, ...
                       'CheckGradients',true, ...
                       'PlotFcn','optimplotfval', ...
                       'Display','iter');

% Initial Condition z0
z0 = zeros(N*(nx + nu) + nx,1);

% ~~~~~~~~~~~~~~~~~~~~~~ Optimization Parameters~~~~~~~~~~~~~~~~~~~~~~~~ %

parameters()

% ~~~~~~~~~~~~~~~~~~~~~~ Constraint and OF ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ %

ObjFun = @(z) cost_and_grad(z,param);
NLcon = @(z) con_and_grad(z,param);

% Maximum error on state reference and control action
max_errx = 0.01;       % [m]
max_errv = 100;        % [m/s]
max_u    = 45/180*pi;  % [rad]
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
    u(:,ii+1) = z((1 + nx + ii*(nu + nx)):(nx + nu + ii*(nu + nx)));   % [rad] 
end

vBall = sqrt(x(1,:).^2 + x(3,:).^2);                                   % [m/s]
err_norm = sqrt( (x(2,:)-xref(2,:)).^2 + (x(4,:)-xref(4,:)).^2 );      % [m]

%% Check for constraint violation
% constraintCheck(x,u,param)

%% Save solution
curdir = pwd;
targetpath = strcat(fileparts(pwd),'\OptimalResults/'); cd(targetpath)
save(strcat('Optimal_',trackname),'x','t','u','xref','R','Q','P'); cd(curdir)

%% Plots
postprocess()
    