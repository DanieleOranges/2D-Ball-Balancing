function [res] = LQR_matrix(circuit, h)

P    = circuit.P   ;
Q    = circuit.Q   ;
R    = circuit.R   ;
t    = circuit.t   ;
u    = circuit.u   ;
x    = circuit.x   ;
xref = circuit.xref;




u = [[0;0],u];
x = x';
time = t;
%% Re-sample the optimal trajectory due to acquisition frequency constraint

% Time discretization in N = number of time intervals
% N = 1000;
% h = 0.02;
T = 0:h:t(end);
N = length(T);

Ns = size(x,2); % number of states
Nc = size(u,1); % number of controls

% Sampled time history
T = linspace(0,time(end),N);

% Interpolation/sampling of the state and control 
xk = zeros(N,Ns);
uk = zeros(N,Nc);
for ii = 1:Ns
    xk(:,ii) = interp1(time,x(:,ii),T);
end
for ii = 1:Nc
    uk(:,ii) = interp1(time(1:end),u(ii,:),T);
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
[Tp,PP] = ode23(@(t,p) DRE(t,p,Q,R,xk,uk,T), flip(T), p0, options);

% From backward to forward dynamics (they are stored in the reversed order)
PP = flipud(PP);
Tp = flipud(Tp);

% Transformation Vector -> Matrix
PP_Matrix = zeros(Ns,Ns);

% Computation of the gain matrix in time, Uncontrolled stability matrix,
% Controlled stability matrix along the trajectory
K = zeros(Nc,Ns,N);
A = zeros(Ns,Ns,N);
C = zeros(1,Ns);
C(1,2) = 1;
C(1,4) = 1;
% D = zeros(Nc);
Fu = zeros(N,Ns,Ns);
PolesUC = zeros(N,Ns);
PolesC = zeros(N,Ns);
Xp = zeros(N,Ns);
for ii = 1:N % Note: try also reshape.m
    % transformation vector -> matrix
    PP_Matrix(1:end) = PP(ii,:)';
    % control matrix G
    B = fu(u,T(ii),time);
    % Uncontrolled state stability matrix
    A(:,:,ii) = fx(xk(ii,:));
    % Uncontrolled system poles
    PolesUC(ii,:) = eig(squeeze(A(:,:,ii)));
    % Gain matrix C
    K(:,:,ii) = pinv(R)*B'*PP_Matrix; % R has to be non-null
    %
    PolesC(ii,:) = eig(squeeze(A(:,:,ii)) -B*squeeze(K(:,:,ii)));
end

T = T';

%% Kalman Filter

% how much the system model is reliable?
% Qk = zeros(Ns);
% Qk(1,1) = 1;
% Qk(2,2) = 1;
% Qk(3,3) = 1;
% Qk(4,4) = 1;
% 
% % how much the measurements are reliable?
% Rk = 1;

%% OPTIMAL OBSERVER DESIGN

% Using nominal A
% Anom = squeeze(A(end,:,:));
% [~,~,Ko] = care(Anom',C',Qk,Rk);
% Ko = Ko';

%% Simulink Model

% Gain matrix preparation
K1x = squeeze(K(:,[1,3]));
K1y = squeeze(K(:,[6,8]));
IC = x(1,:)'; 
ICobs = IC;

% ~~~~~~~~~~~~~~~~~~~~~  Disturbances ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ %
% Uniform random 
min_uniform_random=-1;
max_uniform_random=1;
%constant
Wamp = 0.1; % amplitude of the disturbances
%sine
A_sine=0.1;    %amplitude
Frequency_sine=2*pi*10;

% out = sim('SimLQR.slx');
% out.xref.Data = squeeze(out.xref.Data)';
% out.u.Data = squeeze(out.u.Data)';
% out.uref.Data = squeeze(out.uref.Data)';





%% XK modification

xk_mod(:, 1, :) = xk(:, :)';
uk_mod(:, 1, :) = uk(:, :)';

res.uk = uk_mod; 
res.xk = xk_mod;
res.K  = K; 
res.IC = IC;
res.T  = T; 
res.N  = N; 

res.start = [IC(2), IC(4)];
end

%% PLOTS
% close all
% 
% figure; hold on; grid on; axis equal
% plot(out.x.Data(:,2),out.x.Data(:,4),'.b') % Actual Position States
% plot(out.xref.Data(:,2),out.xref.Data(:,4),'.r') % Optimal Reference Position States
% plot(xref(2,:),xref(4,:),'.k'); % Track reference Position
% legend('Actual','Optimal','Reference','interpreter','latex')
% 
% figure; hold on; grid on;
% title('Actual [blue] vs Optimal [red] control','interpreter','latex')
% plot(out.tout,out.u.Data(:,1),'b',out.tout,out.u.Data(:,2),'.-b')
% plot(out.tout,out.uref.Data(:,1),'r',out.tout,out.uref.Data(:,2),'.-r')
% xlabel('$Time [s]$','interpreter','latex')
% 
% % Colore al variare dell'adimensional damping
% figure; hold on; grid on;
% title('$Controlled Poles$','Interpreter','latex')
% h = sin(pi - abs(angle(PolesC)));
% for ii = 1 : size(PolesC,2)
%     scatter(real(PolesC(:,ii)),imag(PolesC(:,ii)),[],h(:,ii));
% end
% bar = colorbar;
% colormap(gca,'jet');
% bar.Label.String = 'Adimensional Damping';
% xlabel('$\Re\{\lambda\}$ [Rad/s]','Interpreter','LaTex');
% ylabel('$\Im\{\lambda\}$ [Rad/s]','Interpreter','LaTex');
% 
% 
% 
% 
% 
% 
% 
% 
