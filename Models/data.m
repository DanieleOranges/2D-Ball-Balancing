%% Data

g = 9.81;   % gravitational acceleration [m / s^2]

% Dimensions   [m]
Lx = 0.143;                         % joint position in x direction 
Ly = 0.184;                         % joint position in y direction 
Lx_plane=0.15;                        % plane dimension in x direction 
Ly_plane=0.20 ;                       % plane dimension in y direction      
rm = 0.025;                        % motor arm length 
lm=0.072 ;                          % motor rod length 
pt = 0.005;                          % plane tickness
d=0.021;                            % plane offset

Mot_Osci_Rang=[-90 ,90];    %(deg)   range di oscilazione dei motori                  
% Ball data                 
rb = 0.02;                          % radius of the ball [m]
mb = 0.265;                         % mass of the ball [kg]
Jb = 0.0000416;                      % rotarional inertia of the ball [kg * m^2]
Jb = 2/5 * mb * rb^2; 
rho_ball = mb/(4/3 * pi * rb^3);    % ball density [Kg/m^3]

rho_plane=880;         %(kg/m^3) densita del piano
rho_beam=7500;      % (kg/m^3) densita delle aste

% TFs
% V2theta = ((pi/2))/10;  % rad/V
V2theta = 0.20297;
tau_mot = 0.045691;     % s
tau_sens = 0.041813;    % s
rate_limit = 20;    % V/s
% delay_mot = 0.01;
% delay_sens = 0.01;
delay_board = 0.01;

V2theta = 0.20297
tau_mot = 0.045691
tau_sens = 0.041813
delay_board = 0.028815

% Sim data
T_end=13;                  % [s] end time sim
dt=1e-3;                   % time step
time = [0:dt:T_end];       % time array
IC        = [0.0 0.0];     %

% REF input
% constant -> A*ones(length(time),1);
% sine     -> A*sin(2*pi*frequency*time + phi);

% ref.x.v = 0.03*ones(length(time),1);
% ref.x.t = time;
% ref.y.v = 0.03*ones(length(time),1);
% ref.y.t = time;
% 
ref.x.v = 0.04*sin(2*pi*0.2*time + 0);
ref.x.t = time;
ref.y.v = 0.04*sin(2*pi*0.2*time + pi/2);
ref.y.t = time;



% noise_power  = 0.00000004;
Ntension=5e-06;
Nsystem=0e-10;
Nsensor=0e-08;

rf_treshold = 2; 
rf_amp = 1;         % N
%cornice
Lx_cornice=0.15;         %(cm) dimensione X della cornice (meta)
Ly_cornice=0.20;         %(cm) dimensione Y della cornice (meta)
H_cornice=0.005;         %(cm) spessore cornice
W_cornice=0.05;           %(cm) altezza cornice

% Pos distance
contact_treshold = 1e2; 


%% Equation of Motion (simplified)
% syms theta_x theta_y
% theta_x_ref = 0/180*pi;
% theta_y_ref = 0/180*pi;
% 
% Kbbx = (mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Lx) * sin(theta_x);    % x direction transfer function
% Kbbx_lin = subs(Kbbx,theta_x_ref) + (theta_x-theta_x_ref)*subs(diff(Kbbx,theta_x),theta_x_ref);
% Kbbx = double(subs(Kbbx_lin,1));
% 
% Kbby = (mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Ly) * sin(theta_y);    % y direction transfer function
% Kbby_lin = subs(Kbby,theta_y_ref) + (theta_y-theta_y_ref)*subs(diff(Kbby,theta_y),theta_y_ref);
% Kbby = double(subs(Kbby_lin,1));

% Modifica Ernia
Kbbx = (mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Ly);    % x direction transfer function
Kbby = (mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Lx);    % y direction transfer function


%% PID

PID(1).Kp     = 3;          % 3
PID(1).Ki     = 2.4;          % 2.4
PID(1).Kd     = 1.5;          % 1.5
PID(1).filter = 4.5;

PID(2).Kp     = 1.90389213912358 ;
PID(2).Ki     = 0.330968409924509;
PID(2).Kd     = 2.70762690974303;
PID(2).filter = 4.5;

PID(3).Kp     = 0.9;
PID(3).Ki     = 0.256;
PID(3).Kd     = 27.1;
PID(3).filter = 6;

PID(4).Kp     = 30;
PID(4).Ki     = 6;
PID(4).Kd     = 20;
PID(4).filter = 5;

PID(5).Kp     = 30;
PID(5).Ki     = 5;
PID(5).Kd     = 20;
PID(5).filter = 5;

PID(6).Kp     = 30;
PID(6).Ki     = 3;
PID(6).Kd     = 25;
PID(6).filter = 5;

PID_sim = PID(4); 