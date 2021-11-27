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
t0 = 0;                    % Initial time [s]
tf = 10;                   % Final time [s]
h  = 0.05;                 % Temporal discretization [s]
N  = tf/h +1;              % Number of spacesteps/timesteps [~]
t  = 0:h:N*h;              % Time array [s]

%% Reference generation
ref  = load('Monza.mat');
% ref  = load('Skidpad.mat');
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
Lu =@(x,u) R'*u;
px =@(x)   P*(x - xref(:,end));

%% Setup minimization problem

% Options
options = optimoptions('fmincon', ...
                       'MaxFunctionEvaluations',2e+04, ...
                       'SpecifyObjectiveGradient',false, ...
                       'SpecifyConstraintGradient',true, ...
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
max_errx = 0.02;       % [m]
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

vBall = sqrt(x(1,:).^2 + x(3,:).^2);                                   % [m/s]
err_norm = sqrt( (x(2,:)-xref(2,:)).^2 + (x(4,:)-xref(4,:)).^2 );      % [m]

%% Save solution
save('OptimalResults.mat','x','t','u','xref')

%% Plots
close all

figure; hold on; grid on; title('Trajectory Comparison','Interpreter','latex');
h1 = plot(x(2,:),x(4,:),'LineWidth',2); 
plot(x(2,:),x(4,:),'*b','LineWidth',2); 
plot(x(2,1),x(4,1),'*g','MarkerSize',20); axis equal
h2 = plot(xref(2,:),xref(4,:),'*k','LineWidth',2);
lgd = legend([h1,h2],{'$Trajectory$','$Reference$'},'Interpreter','LaTex');
xlabel('$X Position [m]$','Interpreter','latex')
ylabel('$Y Position [m]$','Interpreter','latex')

figure; hold on; grid on; title('$\|\varepsilon\|_2$','Interpreter','latex')
plot(t,err_norm)
xlabel('$Time [s]$','Interpreter','latex');
ylabel('$Error Norm_2$','Interpreter','latex');

figure; hold on; grid on; title('$Control Effort$','Interpreter','latex');
plot(t(2:end),u*180/pi);
xlabel('$Time [s]$','Interpreter','latex');
ylabel('$Control Effort [deg]$','Interpreter','latex');
legend('$U_x$','$U_y$','interpreter','latex')

figure; hold on; grid on; title('$Trajectory-Speed colorBox$','Interpreter','latex')
axis equal
scatter(x(2,:),x(4,:),16,vBall*1000,'filled');
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

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Animation ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ %
animation_flag = 1;
if animation_flag == 1
    counter = 1;
    figure; hold on; grid on; axis equal; title('Real time Trajectory')
    xlim(2*[min(x(2,:)) max(x(2,:))])
    ylim(2*[min(x(4,:)) max(x(4,:))])
    pause(0.1)
    plot(xref(2,:),xref(4,:),'k','LineWidth',2);
    for ii = 1 : length(u)
        plot(x(2,ii),x(4,ii),'*g')
        h1(counter) = quiver(x(2,ii),x(4,ii), ...
                             x(1,ii),x(3,ii),'b');
        pause(h); counter = counter + 1;
        if rem(ii,4) == 0
           for jj = 1 : counter-1
               h1(jj).Visible = 0;
           end
           counter = 1;
        end
    end
    clear h1
end
    