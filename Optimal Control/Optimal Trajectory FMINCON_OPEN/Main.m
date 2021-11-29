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
tau0 =   0;                    % Initial time [~]
tauf =   1;                    % Final time [~]
tf0  =  20;

% Dimension Control
N  = 500;                   % Number of spacesteps/timesteps [~]
h  = 1/(N-1);            
tau  = 0:h:N*h;             % Time array [~]

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
nt = 1;          % Final time dimension 

%% Functional Weights definition
% Control Cost
R = 1*[ 0.1,     0;
          0,   0.1];

% State Cost
Q = 0*[ 0,  0,  0,  0;
      0,  1,  0,  0;
      0,  0,  0,  0;
      0,  0,  0,  1];

% Final State Cost
P = 0.1*[ 0,  0,  0,  0; 
      0, 1,  0,  0;
      0,  0,  0,  0;
      0,  0,  0, 1];

% Time Cost
T = 1;

% Cost Function
L = @(x,u,xref,h) 0.5*(x-xref)'*Q*(x-xref) + 0.5*u'*R*u + T.*h; % Running cost
p = @(x) 0.5*(x - x_f)'*P*(x - x_f) ;                    % Final cost

% Cost function partial derivatives
Lx =@(x,u,xref) Q*(x - xref); 
Lu =@(x,u)      R'*u;
px =@(x)        P*(x - xref(:,end));

%% Setup minimization problem

% Options
options = optimoptions('fmincon', ...
                       'Algorithm','interior-point', ...
                       'MaxFunctionEvaluations',1e+05, ...
                       'SpecifyObjectiveGradient',false, ...
                       'SpecifyConstraintGradient',false, ...
                       'CheckGradients',true, ...
                       'Display','iter-detailed', ...
                       'UseParallel',true, ...
                       'OutputFcn',@outfun);

% Initial Condition z0
z0 = zeros(N*(nx + nu) + nx +nt,1);
z0(end) = tf0;

% ~~~~~~~~~~~~~~~~~~~~~~ Optimization Parameters~~~~~~~~~~~~~~~~~~~~~~~~ %

parameters()

% ~~~~~~~~~~~~~~~~~~~~~~ Constraint and OF ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ %

ObjFun = @(z) cost_and_grad(z,param);
NLcon = @(z) con_and_grad(z,param);

% Maximum error on state reference and control action
param.max_errx = 0.001;       % [m]
param.max_errv = 100;        % [m/s]
param.max_u    = 80/180*pi;  % [rad]
param.tmin     = 1;          % [s]
param.tf0      = tf0;        % [s]

[lb,ub] = bound_define(param);

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

tf = z(end,:);
t  = tau*tf;

vBall = sqrt(x(1,:).^2 + x(3,:).^2);                                   % [m/s]
err_norm = sqrt( (x(2,:)-xref(2,:)).^2 + (x(4,:)-xref(4,:)).^2 );      % [m]

%% Save solution
curdir = pwd;
targetpath = strcat(fileparts(pwd),'\OptimalResults/'); cd(targetpath)
save(strcat('Optimal_',trackname),'x','t','u','xref','R','Q','P'); cd(curdir)

%% Plots
postprocess()
    