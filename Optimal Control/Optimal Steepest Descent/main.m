%% ~~~~~~~~~~~~~ Closed End Optimal Control Algorithm ~~~~~~~~~~~~~~~~~~~ %

% 1) u(t) is guessed
% 2) forward dynamic equation integration
% 3) calculation of final adjoint vector
% 4) backward integration of adjoint vector dynamics
% 5) calculation of dH/du
% 6) steepest descent iteration control on u(t)

% min { J = 0.5*(x(end)-xref(end))*F*(x(end)-xref(end)) + integral(
%       0.5*u*R*u + 0.5*(x-xref)*Q*(x-xref) , [t0,t1]) }
% s.t. :
% g(x(t),u(t)) -> f(x(t),u(t),t) - xp = 0     System dynamics constraint
% c(x(t)) -> norm2(x-xref) - err_lim <= 0     Limit error constraint       
% h(u(t)) -> abs(u) - abs(u_max)     <= 0     Control effort constraint 

% Used terms:
% A = df/dx
% B = df/du
% Lx = dL/dx 
% Lu = dL/du

% Optimality equations
%
% 1) lambdap = -A'*lambda - Lx' - Lx'*mu 
% 2) dH/du   = Lu + lambda'*B + mu'Lu  
% 3) lambda(t1) = dPhi/dx'|(t1)
% 

% Phisical variables
% x -> [x1 x2 x3 x4]' = [xp x yp y]'
% u -> [u1 u2]'       = [theta_x theta_y]'

%% Intro
clear
clc
close all

set(0,'DefaultFigureWindowStyle','docked')

%% Data Callback and initialization
data
Vlim = 1;

% Time discretization
t0 = 0; 
dt = 1e-02;
tf = 1;
time = (t0:dt:tf);       
Nsegment = length(time);

% States
nstates   = 4;
% Controls
ncontrols = 2;

Phi = @(F)  0.5*(x(nstates,end)-xref(nstates,:))'*F*(x(nstates,end)-xref(nstates,:));
L   = @(R,Q) 0.5*u'*R*u + 0.5*(x-xref)'*Q*(x-xref);

%% Parameter matrices

% From mechanical system constraint
obj.A  =   [0,  1,  0,  0; 
            0,  0,  0,  0; 
            0,  0,  0,  1; 
            0,  0,  0,  0];

obj.B  =  [Kbbx*1,      0;
                0,      0;
                0, Kbby*1;
                0,      0];

% From cost functional 
obj.Lx = Q*(x-xref);
obj.Lu = R*u;

% Additional constraint c = sqrt(xp^2+yp^2) - Vlim == 0
% obj.Cx = [x1/(x1^2 + x3^2)^(1/2), 0, x3/(x1^2 + x3^2)^(1/2), 0];
obj.Cx = zeros(nstates) + diag([2*Kbbx*u(1,:),0,2*Kbby*u(2,:),0]);
obj.Cu = [0, 0];

%% Input reference
xref = [ linspace(0,1,Nsegment);
                              0;
         linspace(0,1,Nsegment);
                              0];

%% Boundary conditions
x_i = [xref(1,1); 
               0;
       xref(3,1);
               0];

lambda_f = F*(x(4,:)-xref(4,:));

%% Weights for functional
% R
% F 
% Q 

%% Iterative procedure
% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Options ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ %
options = odeset('RelTol', 1e-4, 'AbsTol',[1e-4 1e-4 1e-4 1e-4]);
Nmax = 1e+03;                       % Maximum number of iterations
u    = zeros(2,Nsegment);           % guessed initial control  u = 0
step = 1e-2;                        % speed of control adjustment
eps  = 1e-2;                        % Exit tollerance condition


% Forward integration of state dynamics with assumed control u(ii,t)
[~,x] = ode45(@(t,x) stateEq(t,x,u,time), time, x_i, options);

% Final values of the adjoint vector (dPhi/dx)|tf
lambdaf = [P(1,1)*(x1(end)-ref.x(end));
                                     0;
           P(3,3)*(x3(end)-ref.y(end));
                                     0]; 

% Backward integration of adjoint dynamics 

%% Plot

%% Optional
% save('~.mat','X',"x1",'x2','x3','x4',"ref","u","time","J","elapsed_time")