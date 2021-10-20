clear
clc
close all

%% Data

g = 9.81;   % gravitational acceleration [m / s^2]

% Dimensions   [m]
Lx = 0.143;                         % joint position in x direction 
Ly = 0.184;                         % joint position in y direction 
Lx_plane=0.15;                        % plane dimension in x direction 
Ly_plane=0.20 ;                       % plane dimension in y direction      
rm = 0.0245;                        % motor arm length 
lm=0.072 ;                          % motor rod length 
pt = 0.005;                          % plane tickness
d=0.021;                            % plane offset

Mot_Osci_Rang=[-80 ,80];    %(deg)   range di oscilazione dei motori                  
% Ball data                 
rb = 0.02;                          % radius of the ball [m]
mb = 0.265;                         % mass of the ball [kg]
Jb = 0.0000416;                     % rotarional inertia of the ball [kg * m^2]
rho_ball = mb/(4/3 * pi * rb^3);    % ball density [Kg/m^3]

% Sim data
ref = [0.00 0.00];
IC  = [0.02 0.02];


rho_plane=880;         %(kg/m^3) densita del piano
rho_beam=7500;      % (kg/m^3) densita delle aste

%cornice
Lx_cornice=0.15;         %(cm) dimensione X della cornice (meta)
Ly_cornice=0.20;         %(cm) dimensione Y della cornice (meta)
H_cornice=0.005;         %(cm) spessore cornice
W_cornice=0.02;           %(cm) altezza cornice


% noise_power  = 0.00000004;
noise_power = 0; 
noise_sample = 0.05; 

%% Equation of Motion (simplified)
syms theta_x theta_y
theta_x_ref = 0/180*pi;
theta_y_ref = 0/180*pi;

Kbbx = (mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Lx) * sin(theta_x);    % x direction transfer function
Kbbx_lin = subs(Kbbx,theta_x_ref) + (theta_x-theta_x_ref)*subs(diff(Kbbx,theta_x),theta_x_ref);
Kbbx = double(subs(Kbbx_lin,1));

Kbby = (mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Ly) * sin(theta_y);    % y direction transfer function
Kbby_lin = subs(Kbby,theta_y_ref) + (theta_y-theta_y_ref)*subs(diff(Kbby,theta_y),theta_y_ref);
Kbby = double(subs(Kbby_lin,1));


%% PID

PID.v1.Kp     = 3;
PID.v1.Ki     = 2.4;
PID.v1.Kd     = 1.5;
PID.v1.filter = 4.5;

PID.v2.Kp     = 1.90389213912358 ;
PID.v2.Ki     = 0.330968409924509;
PID.v2.Kd     =  2.70762690974303;
PID.v2.filter = 4.5;



PID_sim = PID.v2; 