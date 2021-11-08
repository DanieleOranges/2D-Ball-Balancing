%%
% NEIGHBORING OPTIMAL CONTROL VIA LINEAR QUADRATIC FEEDBACK
% Mechatronic systems and Lab. 
% Example N°2
% Riva Emanuele ** emanuele.riva@polimi.it **

clear 
close all
clc

global L w0 zeta m g

%% Data
g = 9.81; 
L = 0.1;
w0 = sqrt(g/L);
zeta = 0.02;
m = 1;

% weight on the control action
R = 1;

% weight on the (relative) state
Q = zeros(2);
Q(1,1) = 1;
Q(2,2) = 1;

% Normalization variables
dQpMax = 20;             %[rad/s]
dQMax = 1;              %[rad]
dCMax = 1;              %[Nm]

Q(1,1) = Q(1,1)./dQpMax.^2;
Q(2,2) = Q(2,2)./dQMax.^2;

R = R./dCMax.^2;

%%

% Final target
xf = [0,pi];
cf = 0;

Ns = 2; % number of states
Nc = 1; % number of controls

%% LQR @(Es 2) Infinite time control around the final equilibrium position

% Stability and Control matrix
A = fx(xf);
B = fc();

% Poles of the uncontrolled system
PolesUC = eig(A);

% Gain matrix and Poles of the controlled system
[K,PP,PolesC] = lqr(A,B,Q,R);

figure;
ax = axes;
plot(real(PolesUC),imag(PolesUC),'x','LineWidth',2,'color','b'); hold on; grid on; box on;
plot(real(PolesC),imag(PolesC),'x','LineWidth',2,'color','r');
xlabel('$\Re\{\lambda\}$ [rad/s]','Interpreter','LaTex')
ylabel('$\Im\{\lambda\}$ [rad/s]','Interpreter','LaTex')
legend({'Uncontrolled','Controlled'},'Interpreter','LaTex')
ax.FontSize = 16;
ax.TickLabelInterpreter = 'LaTex';

%% Simulink Model

% IC = xf';
IC = [0,pi-pi*0.1]';
Wamp = 0.1;
tf = 10;

sim('SimExe2.slx')

Xs = squeeze(Xs.data);
Xref = squeeze(Xref.data);
U = squeeze(U.data);
Uopt = squeeze(Uopt.data);
time = squeeze(time.data);

FigTag = figure;
ax = axes;
plot(time,Xs(:,1)'-Xref(1,:),'LineWidth',1,'LineStyle','-','Color','k');
hold on; grid on;
xlabel('$t$ [s]','Interpreter','LaTex')
ylabel('$\dot{\delta\theta}$ [rad/s]','Interpreter','LaTex')
ax.FontSize = 14;
ax.TickLabelInterpreter = 'LaTex';

% print(FigTag,'fig3_6.jpeg','-djpeg','-r600')

FigTag = figure;
ax = axes;
plot(time,Xs(:,2)'-Xref(2,:),'LineWidth',1,'LineStyle','-','Color','k');
hold on; grid on;
xlabel('$t$ [s]','Interpreter','LaTex')
ylabel('$\delta\theta$ [rad]','Interpreter','LaTex')
ax.FontSize = 14;
ax.TickLabelInterpreter = 'LaTex';

% print(FigTag,'fig3_7.jpeg','-djpeg','-r600')

FigTag = figure;
ax = axes;
plot(time,U-Uopt(:,1),'LineWidth',1,'LineStyle','-','Color','k');
hold on; grid on;
xlabel('$t$ [s]','Interpreter','LaTex')
ylabel('$\delta C$ [Nm]','Interpreter','LaTex')
ax.FontSize = 14;
ax.TickLabelInterpreter = 'LaTex';
drawnow

% print(FigTag,'fig3_8.jpeg','-djpeg','-r600')


