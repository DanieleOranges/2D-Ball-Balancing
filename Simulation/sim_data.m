% %% Data
% clear
% clc
% close all
addpath('script')
current = pwd; 

%% Import Control Data

cd('..\')
control_data
cd(current)

circ1   = monza; 
%%
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
rho_plane=880;                       %(kg/m^3) densita del piano
rho_beam=7500;                  % (kg/m^3) densita delle aste

% Vecchi parametri
V2theta = ((pi/2))/10;  % rad/V ORIGINALE

%% Parametri sperimentali

delay_board_x = 0.01; 
delay_board_y = 0.01; 

grid_pace = 0.7e-3; %[m]

% Estimation result(s):
V2theta_x = 0.16565;
tau_mot_x = 0.066472;
tau_sens_x = 0.025331;
% Estimation result(s):
V2theta_y = 0.15936;
tau_mot_y = 0.04644;
tau_sens_y = 0.04628;


bias_Vx = 0; 
bias_Vy = 0; 



rate_limit = 20;    % V/s

% Noise parameters
Ntension =  0.5e-03;
Nsystem  =  0e-10;
Nsensor  =  5e-10;
noise_seed = round([23341]*rand()); 

%% Sim data
T_end      = 50;            % [s] end time sim
dt         = 1e-3;          % time step
time       = [0:dt:T_end];  % time array
IC         = [0.0 0.0];     % Initial Condition

%% Input references
% constant -> A*ones(length(time),1);
% sine     -> A*sin(2*pi*frequency*time + phi);
% 
% ref_Cx = 0.06; 
% ref_Cy = 0.06; 
% 
% ref.x.v = ref_Cx*ones(length(time),1);
% ref.x.t = time;
% ref.y.v = ref_Cy*ones(length(time),1);
% ref.y.t = time;
% 
% freq = 0.3; 
% ref.x.v = ref_Cx*sin(2*pi*freq*time);
% ref.x.t = time;
% ref.y.v = ref_Cy*sin(2*pi*freq*time + pi/2);
% ref.y.t = time;
% 
% ref.x.v = x';
% ref.x.t = linspace(0,T_end,length(x));
% ref.y.v = y';
% ref.y.t = linspace(0,T_end,length(y));
% 
% rf_treshold = 2; 
% rf_amp = 1;              

%% Multibody data
Lx_cornice=0.15;         %(cm) dimensione X della cornice (meta)
Ly_cornice=0.20;         %(cm) dimensione Y della cornice (meta)
H_cornice=0.005;         %(cm) spessore cornice
W_cornice=0.05;           %(cm) altezza cornice

% Pos distance
contact_treshold = 1e2; 

% Attrito
mu_static = 0.5; 
mu_dynamic = 0.3; 

%% Equation of Motion (simplified)
Kbbx = (mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Ly);    % x direction transfer function
Kbby = (mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Lx);    % y direction transfer function


%% PID
% 
% PID(1).Kp     = 3;           
% PID(1).Ki     = 2.4;         
% PID(1).Kd     = 1.5;         
% PID(1).filter = 4.5;
% 
% PID(2).Kp     = 1.90389213912358 ;
% PID(2).Ki     = 0.330968409924509;
% PID(2).Kd     = 2.70762690974303;
% PID(2).filter = 4.5;
% 
% PID(3).Kp     = 0.9;
% PID(3).Ki     = 0.256;
% PID(3).Kd     = 27.1;
% PID(3).filter = 6;
% 
% PID(4).Kp     = 30;
% PID(4).Ki     = 6;
% PID(4).Kd     = 20;
% PID(4).filter = 5;
% 
% PID(5).Kp     = 30;
% PID(5).Ki     = 5;
% PID(5).Kd     = 20;
% PID(5).filter = 5;
% 
% PID(6).Kp     = 30;
% PID(6).Ki     = 3;
% PID(6).Kd     = 25;
% PID(6).filter = 5;
% 
% PID(7).Kp     = 1.95;
% PID(7).Ki     = 0.04;
% PID(7).Kd     = 21.15;
% PID(7).filter = 5; % era 500 da PID TUNER
% 
% % bandwidth: 3.518 [rad/s] | phase margin: 78.3 [deg]  
% PID(7).Kp     = 1.95;
% PID(7).Ki     = 0.04;
% PID(7).Kd     = 21.15;
% PID(7).filter = 5;  % era 500 da PID TUNER
% 
% % bandwidth:    7 [rad/s] | phase margin: 63.9 [deg]
% PID(8).Kp     = 8.65;
% PID(8).Ki     = 0.35;
% PID(8).Kd     = 46.95;
% PID(8).filter = 5;  % era 500 da PID TUNER
% 
% % bandwidth:  3.857 [rad/s] | phase margin: 40.5 [deg]
% PID(9).Kp     = 37.6051;
% PID(9).Ki     = 15.4718;
% PID(9).Kd     = 22.2032;
% PID(9).filter = 5; % era 500 da PID TUNER
% 
% % PID provati a LAB04
% PID(10).Kp     = 18.57;
% PID(10).Ki     = 1.59;
% PID(10).Kd     = 21.6;
% PID(10).filter = 579.09;
% 
% PID(11).Kp     = 18.57;
% PID(11).Ki     = 1.59;
% PID(11).Kd     = 21.6;
% PID(11).filter = 10;
% 
% PID(12).Kp     = 18.57;
% PID(12).Ki     = 3;
% PID(12).Kd     = 21.6;
% PID(12).filter = 10;
% 
% % PID nuovo Daniele
% PID(13).Kp     = 7.21785018869804;
% PID(13).Ki     = 0.222865836062397;
% PID(13).Kd     = 24.2951589881292;
% PID(13).filter = 450;



%% taratura nuova

% Trovato sperimentalmente con Daniele
PID(1).x.Kp     = 18.57;
PID(1).x.Ki     = 3;
PID(1).x.Kd     = 21.6;
PID(1).x.filter = 10;
PID(1).y = PID(1).x;

% X con 18° e 5 rad/s balanced
PID(2).x.Kp     = 56.5;
PID(2).x.Ki     = 2.4;
PID(2).x.Kd     = 29.4;
PID(2).x.filter = 52;

PID(2).y.Kp     = 49.9;
PID(2).y.Ki     = 2.14;
PID(2).y.Kd     = 22.86;
PID(2).y.filter = 52;

% X con 25° e 5 rad/s balanced
PID(3).x.Kp     = 37.6;
PID(3).x.Ki     = 1.58;
PID(3).x.Kd     = 30.9;
PID(3).x.filter = 52;

PID(3).y.Kp     = 35.1;
PID(3).y.Ki     = 1.49;
PID(3).y.Kd     = 24.16;
PID(3).y.filter = 52;


% Daniele sperimentale 
PID(4).x.Kp     = 22.5;
PID(4).x.Ki     = 0.2; 
PID(4).x.Kd     = 18;
PID(4).x.filter = 20; 

PID(4).y = PID(4).x;

% bw 3.8 pm 34
PID(5).x.Kp     = 12.53 ;
PID(5).x.Ki     = 1.44  ;
PID(5).x.Kd     = 23.19 ;
PID(5).x.filter = 20.73 ;

PID(5).y = PID(5).x;

% 
PID(6).x.Kp     = 19.3;
PID(6).x.Ki     = 3.55;
PID(6).x.Kd     = 25.82;
PID(6).x.filter = 44.06;

PID(6).y = PID(6).x;

PID(7).x.Kp     = 29;
PID(7).x.Ki     = 0.5;
PID(7).x.Kd     = 20;
PID(7).x.filter = 20; 

PID(7).y = PID(7).x;
