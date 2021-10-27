%% Intro
clear
close all
clc

%% Data Callback
data

% Info:
% State Vector ->   X = [x1,x2,x3,x4] = [x,xp,y,yp]
% Control Vector -> u = [u1,u2]       = [x,y]
% J  = phi(x) + L -> L = 0.5*u'*Q*u  + 0.5*R*(x1-x1ref)^2 + 0.5*(x3-x3ref).^2;
% A  = df/dx
% B  = df/du
% Lx = dJ/dx
% Lu = dJ/du

% Initial and final time ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
t0 = 0; 
dt = 1e-02;
tf = 1;
% Time interval
time = (t0:dt:tf);       % discretize time
Nsegment = length(time);

% Input reference ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% ref  = load('Monza.mat');
% ref.x = interp1(1:length(ref.x), ref.x, linspace(1, length(ref.x), Nsegment), 'nearest')';
% ref.y = interp1(1:length(ref.y), ref.y, linspace(1, length(ref.y), Nsegment), 'nearest')';
% ref.x = linspace(0,1,Nsegment)';
% ref.y = linspace(0,0.5,Nsegment)';
ref.x   = 0.5*sin(2*pi*1*time)';
ref.y   = 0.5*sin(2*pi*1*time + pi/2)';

% Boundary conditions
initx = [ref.x(1);0;ref.y(1);0];       % initial values for states

% Weights and limits ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% weight for the states
R = 2;
% weight for final condition on state
P = 3;
% weights for the control
Q = 0;
% Limit cost for divergence
Jlim = 1e04;

%% Iterative Procedure
% Options ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
options = odeset('RelTol', 1e-4, 'AbsTol',[1e-4 1e-4 1e-4 1e-4]);
Nmax = 1e+05;                       % Maximum number of iterations
u    = zeros(2,Nsegment);           % guessed initial control  u = 0
step = 1e-1;                        % speed of control adjustment
eps  = 1e-2;                        % Exit tollerance condition

ii = 1;
tic
J = zeros(Nmax,1);
while ii < Nmax

   % Forward integration of state dynamics with assumed control u(ii,t)
   [timex,X] = ode45(@(t,x) stateEq(t,x,u,time), time, initx, options);
   x1 = X(:,1); x2 = X(:,2); x3 = X(:,3); x4 = X(:,4);

   % Final values of the adjoint vector (dPhi/dx)|tf
   initp = [P*(x1(end)-ref.x(end));0;P*(x3(end)-ref.y(end));0];   

   % Backwards integrations of adjoint vector dynamics
   [Tlmb,L] = ode45(@(t,lmb) adjointEq(t,lmb,u,time,x1,x2,x3,x4,ref,timex,R), flip(time), initp, options);
   lmb1 = L(:,1);
   lmb1 = interp1(Tlmb,lmb1,timex);
   lmb3 = L(:,3);
   lmb3 = interp1(Tlmb,lmb3,timex);

   % Important: costate is stored in reverse order. The dimension of
   % the adjoint vector may also different from dimension of states
   % Use interpolate to make sure x and lmb is aligned along the time axis
   
   % deltaH calculation
   if exist('dH','var')
      dH_old = dH;
   else 
      dH_old = zeros(2,length(timex));
   end
   dH = pH(x1,lmb1,x3,lmb3,timex,u,time,Q);
   H_Norm = norm(dH);
   
   % Cost functional iteration calculation
   J(ii,1) = 0.5*P*(x1(end)-ref.x(end)).^2 + 0.5*P*(x3(end)-ref.y(end)).^2 + sum(tf/length(timex)*0.5*Q*(u(1,:).^2+u(2,:).^2)) + sum(0.5*R*tf*(((x1-ref.x)).^2+(x3-ref.y).^2)/length(timex));
   
   % Convergence check [dH/du < epsilon]
   if H_Norm < eps
       disp(['Convergence -> Final cost: ',num2str(J(ii,1)),' [-]'])
       break;
   elseif J(ii,1) > Jlim
       disp(['Divergence -> Final cost: ',num2str(J(ii,1)),' [-]'])
       break;       
   else
       % Control for next iteration
       u_old = u;
       u = iterControl(dH,timex,u_old,time,step,dH_old);
   end
   if ii == Nmax
       disp(["Max iterations reached. Final cost: ",num2str(J(ii,1)),' [-]'])
   end
   ii = ii  + 1;
end
J(J==0) = [];
elapsed_time = toc
%% Plots
figure; plot(time,x1); hold on; plot(time,x2)
xlabel('time'); ylabel('~'); grid on; title('x')
yyaxis right
plot(time,u(1,:),'g')
legend('Displacement','Velocity','Control effort')

figure; plot(time,x3); hold on; plot(time,x4)
xlabel('time'); ylabel('~'); grid on; title('y')
yyaxis right
plot(time,u(2,:),'g')
legend('Displacement','Velocity','Control effort')

figure; plot(x1,x3); grid on; hold on;
plot(x1(1),x3(1),'*r','MarkerSize',6); plot(x1(end),x3(end),'*g','MarkerSize',6)
plot(ref.x,ref.y,'-.k')
xlabel('x'); ylabel('y'); grid on; title('Trajectory'); axis equal

figure; plot(1:length(J),J); xlabel('Iterations'); ylabel('Cost functional')

%% Optional 
% save('SineTest.mat',"ref","u","time","J","elapsed_time")