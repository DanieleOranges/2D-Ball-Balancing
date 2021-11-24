clear 
close all
clc

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ %
% Info on system:

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ %


%% Data
% data

% weight on the control action
R = [0.1,0;0,0.1];

% weight on the (relative) state
Q = zeros(4);
Q(1,1) = 0;
Q(2,2) = 10;
Q(3,3) = 0;
Q(4,4) = 10;

% weight on the final target
P = zeros(4);
P(1,1) = 0;
P(2,2) = 2;
P(3,3) = 0;
P(4,4) = 2;

% % Normalization variables
% dQpMax = 1;            %[rad/s]
% dQMax = 1;              %[rad]
% dCMax = 1;              %[Nm]
% 
% Q(1,1) = Q(1,1)./dQpMax.^2;
% Q(2,2) = Q(2,2)./dQMax.^2;
% 
% P(1,1) = P(1,1)./dQpMax.^2;
% P(2,2) = P(2,2)./dQMax.^2;
% 
% R = R./dCMax.^2;

%% Nominal Optimal Trajectory Upload

load('Optimal.mat');

c = u;

X = [x2,x1,x4,x3]; %X = X(:,2:end);
Tc =  time;
Tx =  time;

%___ Plot the nominal (optimal) trajectory _______________________________%

% FigTag = figure;
% ax = axes;
% h2 = plot(Tx,X(:,1),'LineWidth',1); hold on;
% h2.Color = 'b';
% h2.LineStyle = '-';
% h3 = plot(Tx,X(:,2),'LineWidth',1);
% h3.Color = 'b';
% h3.LineStyle = '--';
% 
% hold on; grid on;
% h4 = plot(Tc(1:end-1),c,'LineWidth',1);
% h4.Color = 'r';
% xlabel('$t$ [s]','Interpreter','LaTex');
% ax.FontSize = 16;
% ax.TickLabelInterpreter = 'LaTex';
% xlabel('$t$ [s]','Interpreter','LaTex');
% ylabel('$x,u$','Interpreter','LaTex');
% legend([h2,h3,h4],{'$\theta_p$','$\theta$','$c$'},'Interpreter','LaTex','Location','Best')
% 

% print(FigTag,'fig1.jpeg','-djpeg','-r600')


%% Re-sample the optimal trajectory 

% Time discretization in N = number of time intervals
N = 5000;

Ns = size(X,2); % number of states
Nc = size(c,1); % number of controls

% Sampled time history
T = linspace(0,Tx(end),N);

% Interpolation/sampling of the state and control 
xk = zeros(N,Ns);
ck = zeros(N,Nc);
for ii = 1:Ns
    xk(:,ii) = interp1(Tx,X(:,ii),T);
end
for ii = 1:Nc
    ck(:,ii) = interp1(Tc(1:end),c(ii,:),T);
end

%% LQR - Elaboration

% Option for ODE solver
VectTol = ones(Ns^2,1)*1e-5;
options = odeset('RelTol', 1e-5, 'AbsTol',VectTol);

% initial and final time
t0 = T(1);
tf = T(end);

% boundary conditions
p0 = P(1:end)';

% Integration of the matrix riccati equation
[Tp,PP] = ode23(@(t,p) DRE(t,p,Q,R,xk,T,ck,T), flip(T), p0, options);

% From backward to forward dynamics (they are stored in the reversed order)
PP = flipud(PP);
Tp = flipud(Tp);

% Transformation Vector -> Matrix
PP_Matrix = zeros(Ns,Ns);

% Computation of the gain matrix in time, Uncontrolled stability matrix,
% Controlled stability matrix along the trajectory
K = zeros(N,Nc,Ns);
A = zeros(N,Ns,Ns);
Fc = zeros(N,Ns,Ns);
PolesUC = zeros(N,Ns);
PolesC = zeros(N,Ns);
Xp = zeros(N,Ns);
for ii = 1:N % Note: try also reshape.m
    % transformation vector -> matrix
    PP_Matrix(1:end) = PP(ii,:)';
    % control matrix G
    B = fc();
    % Uncontrolled state stability matrix
    A(ii,:,:) = fx(xk(ii,:));
    % Uncontrolled system poles
    PolesUC(ii,:) = eig(squeeze(A(ii,:,:)));
    % Gain matrix C
    K(ii,:,:) = pinv(R)*B'*PP_Matrix; % R has to be non-null
    % Controlled state stability matrix
%     Fc(ii,:,:) = squeeze(A(ii,:,:)) - B*squeeze(K(ii,:,:)).';
    % Controlled system poles
%     PolesC(ii,:) = eig(squeeze(Fc(ii,:,:)));    
    % vector field
%     Xp(ii,:) = f(T(ii),xk(ii,:),ck,T);
end

% squeeze function deletes the unitary dimension

%% Stability analysis of the system along the trajectory

% FigTag = figure;
% FigPos = FigTag.Position;
% FigTag.Position = [FigPos(1)-FigPos(3)*0.25,FigPos(2)-FigPos(4)*0.2,FigPos(3)*1.5,FigPos(4)*1.2];
% filename = 'Trajectory.gif';
% PlotSpeed = 20;
% for ii = 1:N/PlotSpeed
%     
%     clf(FigTag)
%     
%     % Temporal evolution - uncontrolled system
%     ax = subplot(2,2,1); hold on; grid on;
%     plot(real(PolesUC(ii*PlotSpeed,:)),imag(PolesUC(ii*PlotSpeed,:)),'x',...
%                 'LineWidth',2,'Color','k'); hold on; box on;
%     eigRe = real(PolesUC(1:ii*PlotSpeed,:));
%     eigIm = imag(PolesUC(1:ii*PlotSpeed,:));
%     Tmatrix = Tp(1:ii*PlotSpeed)*ones(1,size(eigRe,2));
%     scatter(eigRe(:),eigIm(:),2,Tmatrix(:),'fill'); hold on; box on;
%     colormap jet; caxis([0,Tp(end)]);
%     title('Uncontrolled system','Interpreter','LaTex')
%     xlabel('$\Re\{\lambda\}$ [Rad/s]','Interpreter','LaTex');
%     ylabel('$\Im\{\lambda\}$ [Rad/s]','Interpreter','LaTex');
%     ax.FontSize = 14;
%     ax.TickLabelInterpreter = 'LaTex';
%     ylim([-25,25])
%     xlim([-50,10])
%     
%     % Temporal evolution - controlled system
%     ax = subplot(2,2,2); hold on; grid on;
%     plot(real(PolesC(ii*PlotSpeed,:)),imag(PolesC(ii*PlotSpeed,:)),'x',...
%                 'LineWidth',2,'Color','k'); hold on; box on;
%     eigRe = real(PolesC(1:ii*PlotSpeed,:));
%     eigIm = imag(PolesC(1:ii*PlotSpeed,:));
%     Tmatrix = Tp(1:ii*PlotSpeed)*ones(1,size(eigRe,2));
%     scatter(eigRe(:),eigIm(:),2,Tmatrix(:),'fill'); hold on; box on;
%     colormap jet;  caxis([0,Tp(end)]);
%     title('Controlled system','Interpreter','LaTex')
%     xlabel('$\Re\{\lambda\}$ [Rad/s]','Interpreter','LaTex');
%     ylabel('$\Im\{\lambda\}$ [Rad/s]','Interpreter','LaTex');
%     ax.FontSize = 14;
%     ax.TickLabelInterpreter = 'LaTex';
%     ylim([-25,25])
%     xlim([-50,10])
% 
%     
%     % plot of the trajectory
%     ax = subplot(2,2,[3,4]);
%     hold on; grid on;
%     title('Trajectory','Interpreter','LaTex')
%     scatter(T(1:ii*PlotSpeed),xk(1:ii*PlotSpeed,1),2,T(1:ii*PlotSpeed),'fill');
%     scatter(T(1:ii*PlotSpeed),xk(1:ii*PlotSpeed,2),2,T(1:ii*PlotSpeed),'fill');
%     colormap jet; caxis([0,Tp(end)]);
%     xlabel('$t$ [s]','Interpreter','LaTex');
%     ylabel('$\dot{\theta},\theta$','Interpreter','LaTex');
%     plot(T(ii*PlotSpeed),xk(ii*PlotSpeed,1),'o','LineWidth',1,'color','k');
%     plot(T(ii*PlotSpeed),xk(ii*PlotSpeed,2),'o','LineWidth',1,'color','k');
%     ax.FontSize = 14;
%     ax.TickLabelInterpreter = 'LaTex';
%     hold on; box on;
%     xlim([0,T(end)])
%     ylim([-max(max(abs(xk))),max(max(abs(xk)))])
%     
%     set(gcf,'Color','w')
% %     axis equal
%     drawnow    
%     
%     % Save Animation
%     frame = getframe(FigTag);
%     im = frame2im(frame); 
%     [imind,cm] = rgb2ind(im,256); 
%     if ii==1
%      imwrite(imind,cm,filename,'gif','DelayTime',0.001, 'Loopcount',inf); 
%     else 
%      imwrite(imind,cm,filename,'gif','DelayTime',0.001,'WriteMode','append'); 
%     end         
% end
%     
% 
% filename = 'Anim_phase_plane.gif';
% FigTag = figure;
% FigPos = FigTag.Position;
% FigTag.Position = [FigPos(1)-FigPos(3)*0.25,FigPos(2)-FigPos(4)*0.2,FigPos(3)*1.5,FigPos(4)*1.2];
% for ii = 1:N/PlotSpeed
%     
%     clf(FigTag)    
%     % plot the trajectory in the phase-plane
%     ax = axes;
%     hold on; grid on;
%     title('Trajectory','Interpreter','LaTex')
%     scatter(xk(1:ii*PlotSpeed,2),xk(1:ii*PlotSpeed,1),2,T(1:ii*PlotSpeed),'fill');
%     colormap jet; caxis([0,Tp(end)]);    
%     xlabel('$\theta$','Interpreter','LaTex');
%     ylabel('$\dot{\theta},\theta$','Interpreter','LaTex');
%     plot(xk(end,2),xk(end,1),'o','LineWidth',1,'color','b');
%     plot(xk(1,2),xk(1,1),'o','LineWidth',1,'color','r');
%     ax.FontSize = 14;
%     ax.TickLabelInterpreter = 'LaTex';
%     hold on; box on;
% 
%     xmin = xk(ii*PlotSpeed,2) - 0.2;
%     xmax = xk(ii*PlotSpeed,2) + 0.2;
%     ymin = xk(ii*PlotSpeed,1) - 2;
%     ymax = xk(ii*PlotSpeed,1) + 2;
% 
%     xlim([-pi/2,pi/2])
%     ylim([-15,15])
%     
%     % Plot the vector field Xdot 
%     theta = xmin:(xmax-xmin)/10:xmax; Ntheta = length(theta);
%     theta_p = ymin:(ymax-ymin)/10:ymax; Ntheta_p = length(theta_p);
%     [Th,Th_p] = meshgrid(theta,theta_p);
%     Th = Th(:); Th = Th.';
%     Th_p = Th_p(:); Th_p = Th_p.';
% 
%     Th_pp = - 2*zeta*w0*(-xk(ii*PlotSpeed,1)+Th_p) - w0^2*cos(xk(ii*PlotSpeed,2))*(-xk(ii*PlotSpeed,2)+Th) + ...
%             + squeeze(K(ii*PlotSpeed,:,1))*(xk(ii*PlotSpeed,1) - Th_p)/m/L^2 + ...
%             + squeeze(K(ii*PlotSpeed,:,2))*(xk(ii*PlotSpeed,2) - Th)/m/L^2;
%                
%     h = quiver(Th,Th_p,(-xk(ii*PlotSpeed,1)+Th_p),Th_pp,1);
%     h.Color = 'b';
% 
%     set(gcf,'Color','w')
%     drawnow
%     
% %     % Save Animation
% %     frame = getframe(FigTag);
% %     im = frame2im(frame); 
% %     [imind,cm] = rgb2ind(im,256); 
% %     if ii==1
% %      imwrite(imind,cm,filename,'gif','DelayTime',0.001, 'Loopcount',inf); 
% %     else 
% %      imwrite(imind,cm,filename,'gif','DelayTime',0.001,'WriteMode','append'); 
% %     end     
%     
%                    
% end

T = T';

%% Simulink Model

IC = [0;0;0;0];

K1x = squeeze(K(:,[1,3]));
K1y = squeeze(K(:,[6,8]));

Wamp = 1; % amplitude of the disturbances


sim('SimExe1.slx')

Xs = squeeze(Xs.data);
Xref = squeeze(Xref.data);
U = squeeze(U.data);
Uopt = squeeze(Uopt.data);
time = squeeze(time.data);

FigTag = figure;
ax = axes;
plot(time,Xref(1,:),'LineWidth',1,'LineStyle','--','color','b');
hold on; grid on;
plot(time,Xs(:,1),'LineWidth',0.5,'LineStyle','-','color','r');
xlabel('$t$ [s]','Interpreter','LaTex')
ylabel('$\dot{\theta}$ [rad/s]','Interpreter','LaTex')
ax.FontSize = 14;
ax.TickLabelInterpreter = 'LaTex';

% print(FigTag,'fig3_1.jpeg','-djpeg','-r600')

FigTag = figure;
ax = axes;
plot(time,Xref(2,:),'LineWidth',1,'LineStyle','--','color','b');
hold on; grid on;
plot(time,Xs(:,2),'LineWidth',0.5,'LineStyle','-','color','r');
xlabel('Time [s]','Interpreter','LaTex')
ylabel('$\theta$ [rad]','Interpreter','LaTex')
ax.FontSize = 14;
ax.TickLabelInterpreter = 'LaTex';

% print(FigTag,'fig3_2.jpeg','-djpeg','-r600')

FigTag = figure;
ax = axes;
plot(time,Uopt,'LineWidth',1,'LineStyle','--','color','b');
hold on; grid on;
plot(time,U,'LineWidth',0.5,'LineStyle','-','color','r');
xlabel('$t$ [s]','Interpreter','LaTex')
ylabel('$C$ [Nm]','Interpreter','LaTex')
ax.FontSize = 14;
ax.TickLabelInterpreter = 'LaTex';

% print(FigTag,'fig3_3.jpeg','-djpeg','-r600')

FigTag = figure;
ax = axes;
plot(time,Xs(:,1)'-Xref(1,:),'LineWidth',1,'LineStyle','-','Color','b');
hold on; grid on;
xlabel('$t$ [s]','Interpreter','LaTex')
ylabel('$\dot{\delta\theta}$ [rad/s]','Interpreter','LaTex')
ax.FontSize = 14;
ax.TickLabelInterpreter = 'LaTex';

% print(FigTag,'fig3_4.jpeg','-djpeg','-r600')

FigTag = figure;
ax = axes;
plot(time,Xs(:,2)'-Xref(2,:),'LineWidth',1,'LineStyle','-','Color','b');
hold on; grid on;
xlabel('$t$ [s]','Interpreter','LaTex')
ylabel('$\delta\theta$ [rad]','Interpreter','LaTex')
ax.FontSize = 14;
ax.TickLabelInterpreter = 'LaTex';

% print(FigTag,'fig3_5.jpeg','-djpeg','-r600')

FigTag = figure;
ax = axes;
plot(time,U-Uopt(:,1),'LineWidth',1,'LineStyle','-','Color','b');
hold on; grid on;
xlabel('$t$ [s]','Interpreter','LaTex')
ylabel('$\delta C$ [Nm]','Interpreter','LaTex')
legend({'$\delta c_1$','$\delta c_2$'},'Interpreter','Latex','location','best')
ax.FontSize = 14;
ax.TickLabelInterpreter = 'LaTex';
drawnow

% print(FigTag,'fig3_6.jpeg','-djpeg','-r600')

















