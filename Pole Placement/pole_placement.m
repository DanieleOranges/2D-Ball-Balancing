clear
close all

%% State Space Representation
Kbb = 1;    % mechanical system's gain
tau_mot = 1;   % motor time delay
K_mot = 1;  % motor gain

A = [0, 0, Kbb; % state space A matrix
    1, 0, 0;
    0, 0, -1/tau_mot];

B = [0; 0; K_mot/tau_mot]; % state space B matrix

C = eye(size(A, 1)); % state space C matrix (identity)

D = zeros(size(A, 1), 1);    % state space D matrix   

plant = ss(A, B, C, D); % define state space variable
states = {'xdot', 'x', 'theta'};    % initialize state names
plant.Statename = states;   % assign state names
plant.Outputname = states; % assign output name

%% Integral Action and Pole Placement
A_aug = [0, 0, 0, Kbb; % augmented state space A matrix
    1, 0, 0, 0;
    0, 1, 0, 0;
    0, 0, 0, -1/tau_mot];

B_aug = [0; 0; 0; K_mot/tau_mot]; % augmented state space B matrix

C_aug = eye(size(A_aug, 1)); % augmented state space C matrix (identity)

D_aug = zeros(size(A_aug, 1), 1);    % augmented state space D matrix   

poles_chosen = [-10, -5, -0.5 + 0.25i, -0.5 - 0.25i]; % chosen poles to move
[K, prec] = place(A_aug, B_aug, poles_chosen);  % pole placement
Kx = [K(1 : 2), K(4)];  % all control gains except integral
Ki = K(3);    % integral control gain

A_fullstate = A_aug - B_aug * K;    % full state feedback matrix
plant_fullstate = ss(A_fullstate, B_aug, C_aug, D_aug); % plant with full state feedback
states_aug = {'xdot', 'x', 'intx', 'theta'};    % initialize state names
plant_fullstate.Statename = states_aug;   % assign state names
plplant_fullstateant.Outputname = states_aug; % assign output name












