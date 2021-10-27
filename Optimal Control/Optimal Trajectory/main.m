clear
clc

data

% J  = phi(x) + L || L = 0.5*R*(x1-x1ref)^2;
% A  = [0,0;1,0];
% B  = [cos(u)*Kbbx;0];
% Lx = [0;R*(x1-xref)];
% Lu = 0;

% State Vector -> X = [x1,x2,x3,x4] = [x,xp,y,yp]
% Control Vector -> u = [u1,u2] = [theta_x,theta_y]

% Initial and final time
t0 = 0; 
tf = 40;
% Time interval
Nsegment = 100;                        % Number of time intervals considered
time = linspace(t0, tf, Nsegment);    % discretize time

% Boundary conditions
initx = [0;0;0;0];                    % initial values for states

ref  = load('Monza.mat');
ref.x = interp1(1:length(ref.x), ref.x, linspace(1, length(ref.x), Nsegment), 'nearest')';
ref.y = interp1(1:length(ref.y), ref.y, linspace(1, length(ref.y), Nsegment), 'nearest')';
% ref.x = 0.3*sin(2*pi*1*time)';
% ref.y = 0.3*sin(2*pi*1*time)';

% weight for the control
R = 1;
% weight for final condition on state
P = 1;
% weights for the states
Q = 1;

%% Iterative Procedure
options = odeset('RelTol', 1e-4, 'AbsTol',[1e-4 1e-4 1e-4 1e-4]);

Nmax = 1000;                        % Maximum number of iterations
u = zeros(2,Nsegment);              % guessed initial control  u = 0
step = 1e-5;                        % speed of control adjustment
eps = 1e-2;                         % Exit tollerance condition

ii = 1;
while ii <= Nmax

   % 1) start with assumed control u and move forward
   [timex,X] = ode45(@(t,x) stateEq(t,x,u,time), time, initx, options);
   
   % 2) Move backward to get the adjoint vectos trajectory
   x1 = X(:,1); x2 = X(:,2); x3 = X(:,3); x4 = X(:,4);

   initp = [2*P*(x1(end)-ref.x(end));0;2*P*(x3(end)-ref.y(end));0];   % final values for adjoint vector
   [Tlmb,L] = ode45(@(t,lmb) adjointEq(t,lmb,u,time,x1,x2,x3,x4,ref,timex,Q), flip(time), initp, options);
   lmb1 = L(:,1);
   lmb1 = interp1(Tlmb,lmb1,timex);
   lmb3 = L(:,3);
   lmb3 = interp1(Tlmb,lmb1,timex);

   % Important: costate is stored in reverse order. The dimension of
   % the adjoint vector may also different from dimension of states
   % Use interploate to make sure x and lmb is aligned along the time axis
   
   % 3) Calculate deltaH
   % Variable step size
   if ii == 1
       dH_old = zeros(1,Nsegment);
   else
       dH_old = dH;
   end
   dH = pH(x1,lmb1,x3,lmb3,timex,u,time,R);
   H_Norm = norm(dH);
   
   % 4) Calculate the cost
   J(ii,1) = P*(x1(end)-ref.x(end)).^2 + P*(x3(end)-ref.y(end)).^2 + sum(tf*((x1-ref.x)+(x3-ref.y)).^2/length(timex));
   
   % 5) if dH/du < epsilon, exit
   if H_Norm < eps
       % Display final cost
       disp(['Final cost: ',num2str(J(ii,1)),' [-]'])
       break;
   else
       % 6) adjust control for next iteration
       u_old = u;
       u = iterControl(dH_old,dH,timex,u_old,time,step);
   end
   if ii == Nmax
       disp("Max iterations reached: ")
   end
   ii = ii  + 1;
end
ii = ii - 1;
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

figure; plot(x1,x3); grid on; hold on; plot(ref.x,ref.y,'k')
xlabel('x'); ylabel('y'); grid on; title('Trajectory'); axis equal

figure; plot(1:ii,J); xlabel('Iterations'); ylabel('Cost functional')