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
N  = 200;                   % Number of spacesteps/timesteps [~]
h = tf/(N-1);               % Temporal discretization [s]
time = linspace(t0,tf,N+1); % Time array [s]

%% Reference generation
ref  = load('Monza.mat');
p = interparc(N+1,ref.x,ref.y); ref.x = p(:,1); % Arclength interpolation
                                ref.y = p(:,2); clear p

% ref.x   = 0.05*sin(2*pi/5*time)';
% ref.y   = 0.05*sin(2*pi/5*time + pi/2)';

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
Lu =@(x,u) R'*u;
px =@(x)   P*(x - xref(:,end));

%% Setup minimization problem

% Options
options = optimoptions('fmincon', ...
                       'Algorithm','active-set', ...
                       'MaxFunctionEvaluations',10^4, ...
                       'SpecifyObjectiveGradient',false, ...
                       'SpecifyConstraintGradient',true, ...
                       'CheckGradients',true, ...
                       'Display','iter-detailed');

% Initial Condition z0
z0 = zeros(N*(nx + nu) + nx,1);

% ~~~~~~~~~~~~~~~~~~~~~~ Optimization Parameters~~~~~~~~~~~~~~~~~~~~~~~~ %

parameters()

% ~~~~~~~~~~~~~~~~~~~~~~ Constraint and OF ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ %

ObjFun = @(z) cost_and_grad(z,param);
NLcon = @(z) con_and_grad(z,param);

% Maximum error on state reference and control action
max_errx = 0.05;  % [m]
max_errv = 100;  % [m/s]
max_u    = 100;  % [?]
[lb,ub] = bound_define(xref,max_errx,max_errv,max_u,nx,nu,N);

% linear inequalities
A = [];
b = [];
Aeq = [];
beq = []; 

% Minimize ObjFun s.t. NLcon
[z,fval,exitflag,output,lambda] = fmincon(ObjFun,z0,A,b,Aeq,beq,lb,ub,NLcon);

%% State and control extraction from z

t = 0:h:N*h;    % [t]

x = zeros(nx,N+1); u = zeros(nu,N);
for ii = 0:N
    x(:,ii+1) = z((1 + ii*(nu + nx)):(nx + ii*(nu + nx)));             % [m/s;m;m/s,m]
end    
for ii = 0:N-1
    u(:,ii+1) = z((1 + nx + ii*(nu + nx)):(nx + nu + ii*(nu + nx)));   % [~] 
end

vBall = sqrt(x(1,:).^2 + x(3,:).^2)*1000;                              % [mm/s]
err_norm = sqrt( (x(2,:)-xref(2,:)).^2 + (x(4,:)-xref(4,:)).^2 );      % [m]

%% Plots
close all

figure; hold on; grid on; title('Trajectory Comparison','Interpreter','latex');
h1 = plot(x(2,:),x(4,:),'LineWidth',2); 
plot(x(2,:),x(4,:),'*b','LineWidth',2); 
plot(x(2,1),x(4,1),'*g','MarkerSize',4); axis equal
h2 = plot(xref(2,:),xref(4,:),'*k','LineWidth',2);
lgd = legend([h1,h2],{'$Trajectory$','$Reference$'},'Interpreter','LaTex');
xlabel('$X Position [m]$','Interpreter','latex')
ylabel('$Y Position [m]$','Interpreter','latex')

figure; hold on; grid on; title('$\|\varepsilon\|_2$','Interpreter','latex')
plot(t,err_norm)
xlabel('$Time [s]$','Interpreter','latex');
ylabel('$Error Norm_2$','Interpreter','latex');

figure; hold on; grid on; title('$Control Effort$','Interpreter','latex');
plot(t(2:end),u);
xlabel('$Time [s]$','Interpreter','latex');
ylabel('$Control Effort [~]$','Interpreter','latex');
legend('$U_x$','$U_y$','interpreter','latex')

figure; hold on; grid on; title('$Trajectory-Speed colorBox$','Interpreter','latex')
axis equal
scatter(x(2,:),x(4,:),16,vBall,'filled');
cb = colorbar; cb.Label.Interpreter = 'latex';
cb.Label.String = ('$Ball speed [mm/s]$');
xlabel('$X Position [m]$','Interpreter','latex')
ylabel('$Y Position [m]$','Interpreter','latex')

figure; hold on; grid on; title('$Error Norm_2 colorBox$','Interpreter','latex')
axis equal
scatter(x(2,:),x(4,:),16,err_norm,'filled');
cb = colorbar; cb.Label.Interpreter = 'latex';
cb.Label.String = ('$Error Norm_2 [mm]$');
xlabel('$X Position [m]$','Interpreter','latex')
ylabel('$Y Position [m]$','Interpreter','latex')