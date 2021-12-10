clear
close all

%% Choose Poles as Input

% t_s = 5/max(poles_x_chosen);
% t_s = 1; 
% dom_pole = 5/t_s; 
poles_x_chosen = [-40, -30, -0.8 + 0.25i, -0.8 - 0.25i]; % chosen poles in x direction
poles_y_chosen = [-10, -5,  -0.8 + 0.25i, -0.8 - 0.25i]; % chosen poles in y direction

%% Data Initialization

g = 9.81;   % gravitational acceleration [m/s^2]
mb = 0.265; % mass of the ball [kg]
rb = 0.02;  % radius of the ball [m]
rm = 0.025; % motor arm length [m]
Jb = 0.0000416; % rotarional inertia of the ball [kg * m^2]
Lx = 0.143; % joint position in x direction 
Ly = 0.184; % joint position in y direction 

Kbbx = (mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Ly);    % x direction transfer function
Kbby = (mb * g * rb^2 * rm) / ((mb * rb^2 + Jb) * Lx);    % y direction transfer function
tau_mot_x = 0.066472;
tau_mot_y = 0.04644;
V2theta_x = 0.16565;
V2theta_y = 0.15936;

%% State Space Models
% state-space x direction
A_x = [0, 0, Kbbx; % state space A matrix
    1, 0, 0;
    0, 0, -1/tau_mot_x];

B_x = [0; 0; V2theta_x/tau_mot_x]; % state space B matrix

C_x = eye(size(A_x, 1)); % state space C matrix (identity)

D_x = zeros(size(A_x, 1), 1);    % state space D matrix   

plant_x = ss(A_x, B_x, C_x, D_x); % define state space variable
states_x = {'xdot', 'x', 'theta'};    % initialize state names
plant_x.Statename = states_x;   % assign state names
plant_x.Outputname = states_x; % assign output name

% state-space y direction
A_y = [0, 0, Kbby; % state space A matrix
    1, 0, 0;
    0, 0, -1/tau_mot_y];

B_y = [0; 0; V2theta_y/tau_mot_y]; % state space B matrix

C_y = eye(size(A_y, 1)); % state space C matrix (identity)

D_y = zeros(size(A_y, 1), 1);    % state space D matrix   

plant_y = ss(A_y, B_y, C_y, D_y); % define state space variable
states_y = {'ydot', 'y', 'theta'};    % initialize state names
plant_y.Statename = states_y;   % assign state names
plant_y.Outputname = states_y; % assign output name

%% Integral Actions Augmentations and Pole Calculations
% integral action x direction

A_x_aug = [0, 0, 0, Kbbx; % augmented state space A matrix
    1, 0, 0, 0;
    0, 1, 0, 0;
    0, 0, 0, -1/tau_mot_x];

B_xaug = [0; 0; 0; V2theta_x/tau_mot_x]; % augmented state space B matrix

C_xaug = eye(size(A_x_aug, 1)); % augmented state space C matrix (identity)

D_xaug = zeros(size(A_x_aug, 1), 1);    % augmented state space D matrix   

[Kgain_x, prec_x] = place(A_x_aug, B_xaug, poles_x_chosen);  % pole placement
Kx = [Kgain_x(1 : 2), Kgain_x(4)];  % all control gains except integral
Kxi = Kgain_x(3);    % integral control gain

A_x_fullstate = A_x_aug - B_xaug * Kgain_x;    % full state feedback matrix
% integral action y direction
A_y_aug = [0, 0, 0, Kbby; % augmented state space A matrix
    1, 0, 0, 0;
    0, 1, 0, 0;
    0, 0, 0, -1/tau_mot_y];

B_y_aug = [0; 0; 0; V2theta_y/tau_mot_y]; % augmented state space B matrix

C_y_aug = eye(size(A_y_aug, 1)); % augmented state space C matrix (identity)

D_y_aug = zeros(size(A_y_aug, 1), 1);    % augmented state space D matrix   

[Kgain_y, prec_y] = place(A_y_aug, B_y_aug, poles_y_chosen);  % pole placement
Ky = [Kgain_y(1 : 2), Kgain_y(4)];  % all control gains except integral
Kyi = Kgain_y(3);    % integral control gain

A_y_fullstate = A_y_aug - B_y_aug * Kgain_y;    % full state feedback matrix

%% Export Variables
save('../gain_matrix.mat', 'Kx', 'Kxi', 'Ky', 'Kyi')
