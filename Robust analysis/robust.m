%% Intro
clear all
clc
set(0,'DefaultFigureWindowStyle','docked')
addpath(uigetdir(''))
% addpath(strcat(pwd),)

% Data callback
data

time = (0:dt:tfinal);
pista = load('Monza.mat');
pista.x = interp1(1:length(pista.x), pista.x, linspace(1, length(pista.x), length(time)), 'nearest');
pista.y = interp1(1:length(pista.y), pista.y, linspace(1, length(pista.y), length(time)), 'nearest');

refx = [time;pista.x]';
refy = [time;pista.y]';

% Non linear simulation
out = sim('non_linear_sys_2.slx');

%% Main
% Motor TF
M = tf([1],[0.01 1]);

% Mechanical TF
Gx = tf([(mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Lx)],[1 0 0]);
Gy = tf([(mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Ly)],[1 0 0]);

% Uncertain Mechanical TF
mb = ureal('mb',mb,'Percentage',50);
rb = ureal('rb',rb,'Percentage',20);
Gx_unc = tf([(mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Lx)],[1 0 0]);
Gy_unc = tf([(mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Ly)],[1 0 0]);

% Controller
Rx = tf(PID_sim.Kp) + tf(PID_sim.Ki,[1 0]) + tf([PID_sim.Kd*PID_sim.filter 0],[1 PID_sim.filter]);
Ry = tf(PID_sim.Kp) + tf(PID_sim.Ki,[1 0]) + tf([PID_sim.Kd*PID_sim.filter 0],[1 PID_sim.filter]);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%
% Gy = tf([(mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Ly)],[1 0 0]);
% Ry = tf(PID_sim.Kp) + tf(PID_sim.Ki,[1 0]) + tf([PID_sim.Kd*PID_sim.filter 0],[1 PID_sim.filter]);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%
% LTV expansion
% W = makeweight(.05,9,10);
% Delta = ultidyn('Delta',[1 1]);
% Gx_unc = Gx_unc*(1+W*Delta);

% Open loop TF
Lx     = Rx*M*Gx;
Lx_unc = Rx*M*Gx_unc;
Ly     = Rx*M*Gy;
Ly_unc = Rx*M*Gy_unc;

% Closed loop TF
Cx = feedback(Lx,1);
Cx_unc = feedback(Lx_unc,1);
Cy = feedback(Ly,1);
Cy_unc = feedback(Ly_unc,1);

%% Analysis
opt = robOptions('Display','on');

% Stability margins
stabmargx     = robstab(Cx,opt);
stabmargx_unc = robstab(Cx_unc,opt);
stabmargy     = robstab(Cy,opt);
stabmargy_unc = robstab(Cy_unc,opt);

% Worst gain case scenario
[maxgainx,wcux] = wcgain(Cx);
[maxgainx_unc,wcuy_unc] = wcgain(Cx_unc);
[maxgaint,wcut] = wcgain(Cy);
[maxgainy_unc,wcuy_unc] = wcgain(Cy_unc);

%% Pole placement
px = [-10 -2 -3];
X.tf = M*Gx;
[A,B,C,D] = tf2ss(X.tf.num{1},X.tf.den{1});
[Kx,precision,message] = place(A,B,px);
X.A = A; X.B = B; X.C = C; X.D = D;
% Closed loop ss form
Cx_pp = ss(A-B*Kx,B,C,0);
[NUM,DEN] = ss2tf(Cx_pp.A,Cx_pp.B,Cx_pp.C,Cx_pp.D);
Cx_pp = tf(NUM,DEN); clear NUM DEN
% Open loop tf form
Lx_pp  = Cx_pp/(1-Cx_pp);

py = [-10 -2 -3];
Y.tf = M*Gy;
[A,B,C,D] = tf2ss(Y.tf.num{1},Y.tf.den{1});
[Ky,precision,message] = place(A,B,py);
Y.A = A; Y.B = B; Y.C = C; Y.D = D;
% Closed loop ss form
Cy_pp = ss(A-B*Ky,B,C,0);
[NUM,DEN] = ss2tf(Cy_pp.A,Cy_pp.B,Cy_pp.C,Cy_pp.D);
Cy_pp = tf(NUM,DEN); clear NUM DEN
% Open loop tf form
Ly_pp  = Cy_pp/(1-Cy_pp);


%% Noise in motor tension
% Nmotor  = 
%% Noise in sensors
% Nsensor =
%% Noise in system
% Nsystem =
%% LQR
%% Plots
figure('Name','State-Space 1'); plot(out.x.Data,out.xp.Data,'b'); grid on; hold on
plot(out.y.Data,out.yp.Data,'r'); grid on
xlabel('Displacement');ylabel('Velocity')
title('Position state-space');legend('X','Y')

figure('Name','State-Space 2'); scatter(out.x.Data,out.xp.Data,4,out.tout); grid on; colorbar(); hold on
scatter(out.y.Data,out.yp.Data,4,out.tout);
xlabel('Displacement');ylabel('Velocity')
title('Position state-space');legend('X','Y'); axis equal

figure('Name','Trajectories'); scatter(out.x.Data,out.y.Data,4,out.tout); grid on; colorbar();
xlabel('X');ylabel('Y')
title('Trajectories')

figure('Name','Theta'); plot(out.theta_x); hold on; grid on; plot(out.theta_y)
title('Theta');legend('\Theta_X','\Theta_Y')
xlabel('Time');ylabel('Angle')

% X direction
figure('Name','Step X');step(Cx_unc,'b',Cx,'r',Cx_pp,'g'); legend('Uncertain','Nominal','Pole placement');
xlabel('Time (sec)');ylabel('Ball Position (m)')
subtitle('X')
figure('Name','Bode X');bode(Cx_unc,'b',Cx,'r',Cx_pp,'g'); legend('Uncertain','Nominal','Pole placement')
grid on;

figure('Name','Nyquist X');nyquist(Lx_unc,'b',Lx,'r'); legend('Uncertain','Nominal');
xlim([-10 0]); grid on; subtitle('X')

figure('Name','Rlocus X'); rlocus(Cx,'r',Cx_pp,'g'); legend('Nominal','Pole placement'); grid on;
subtitle('X')

figure('Name','Impulse X'); impulse(Cx_unc,'b',Cx,'r',Cx_pp,'g'); legend('Uncertain','Nominal','Pole placement'); grid on;
subtitle('X')

% Y direction
figure('Name','Step Y');step(Cy_unc,'b',Cy,'r',Cy_pp,'g'); legend('Uncertain','Nominal','Pole placement');
ylabel('Time (sec)');ylabel('Ball Position (m)')
subtitle('Y')

figure('Name','Bode Y');bode(Cy_unc,'b',Cy,'r',Cy_pp,'g'); legend('Uncertain','Nominal','Pole placement')
grid on;

figure('Name','Nyquist Y');nyquist(Ly_unc,'b',Ly,'r'); legend('Uncertain','Nominal');
xlim([-10 0]); grid on; subtitle('Y')

figure('Name','Rlocus Y'); rlocus(Cy,'r',Cy_pp,'g'); legend('Nominal','Pole placement'); grid on;
subtitle('Y')

figure('Name','Impulse Y'); impulse(Cy_unc,'b',Cy,'r',Cy_pp,'g'); legend('Uncertain','Nominal','Pole placement'); grid on;
subtitle('Y')