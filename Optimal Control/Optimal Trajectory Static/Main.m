%% Intro
clear 
close all
clc

% Data:
Kbbx = 1.2070;
Kbby = 0.9381;

% Initial and final time
t0 = 0; 
tf = 10;

% Boundary conditions
% Initial States x_i = [xi;xpi;yi;ypi];
x_i = [10;
        0;
       10;
        0];

% Final States x_f = [xf;xpf,yf,ypf];
x_f = [-10;
         0;
       -10;
         0];
 
% Dynamical system
dx = @(x,u) [           x(2);
              Kbbx*(u(1));
                        x(4);
             Kbby*(u(2))];

% Jacobian of the dynamics
fx = @(x,u) [  0 , 1 , 0 , 0;   
               0 , 0 , 0 , 0;
               0 , 0 , 0 , 1;
               0 , 0 , 0 , 0];

fu = @(x,u) [             0,               0;
             1*Kbbx,               0;
                          0,               0;
                          0, 1*Kbby];
                                                                                      
% weights for the control cost
R = [ 10,   0;
      0,   10];

% weights for state
Q = [ 1,0,0,0;
      0,0,0,0;
      0,0,1,0;
      0,0,0,0];

% weight the final state
P = [  0,0,0,0; 
       0,0,0,0;
       0,0,0,0;
       0,0,0,0];

% Cost function
L = @(x,u) 0.5*x'*Q*x + 0.5*u'*R*u  ; % Running cost
p = @(x) 0.5*(x - x_f)'*P*(x - x_f) ; % Final cost

Lx =@(x,u) Q*x;
Lu =@(x,u) R'*u;
px =@(x)   P*(x - x_f);

%% Setup minimization problem

nx = 4;       % Number of states
nu = 2;       % number of inputs
N = 101;      % number of temporal steps
h = tf/(N-1); % temporal discretization 

options = optimoptions('fmincon',...
    'SpecifyObjectiveGradient',false,'SpecifyConstraintGradient',true,'CheckGradients',true,'Display','iter');

% Initial conditions for the minimization problem
z0 = zeros(N*(nx + nu) + nx,1);

%___ store the necessary stuff in a structure ____________________________%

param.N = N;
param.nu = nu;
param.nx = nx;
param.dx = dx;
param.x_i = x_i;
param.fx = fx;
param.fu = fu;
param.L = L;
param.Lx = Lx;
param.Lu = Lu;
param.p = p;
param.px = px;
param.h = h;

%___ Define objective function and constraints ___________________________%

ObjFun = @(z) cost_and_grad(z,param);
NLcon = @(z) con_and_grad(z,param);

% linear inequalities
A = [];
b = [];
Aeq = [];
beq = []; 
lb = []; % lower bound
ub = []; % upper bound

% Minimize ObjFun s.t. NLcon
[z,fval] = fmincon(ObjFun,z0,A,b,Aeq,beq,lb,ub,NLcon,options);

%% Plot the results

t = 0:h:N*h;

% extract states and control from z
x = zeros(nx,N+1); u = zeros(nu,N);
for ii = 0:N
    x(:,ii+1) = z((1 + ii*(nu + nx)):(nx + ii*(nu + nx)));
end    
for ii = 0:N-1
    u(:,ii+1) = z((1 + nx + ii*(nu + nx)):(nx + nu + ii*(nu + nx)));    
end

figure
ax = axes;
h1 = plot(t,x(1,:)); hold on;
h1.LineWidth = 1;
h1.LineStyle = '-';
h1.Color = 'b';
h2 = plot(t,x(2,:)); hold on;
h2.LineWidth = 1;
h2.LineStyle = '--';
h2.Color = 'b';
h3 = plot(t(1:end-1),u(1,:)); hold on;
h3.LineWidth = 1;
h3.LineStyle = '-';
h3.Color = 'r';
xlim([0,tf])
ylim([-5,15])
ax.TickLabelInterpreter = 'LaTex';
ylabel('$x,u$','Interpreter','LaTex');
xlabel('$t$ [s]','Interpreter','LaTex');
ax.FontSize = 16;

lgd = legend([h1,h2,h3],{'$\dot\theta$','$\theta$','u'},'Interpreter','LaTex');



