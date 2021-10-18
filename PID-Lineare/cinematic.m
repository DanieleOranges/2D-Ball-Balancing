clear
clc
close all

%% Data
Lx = 0.134; % beam length in x direction [m]
Ly = 0.168; % beam length in y direction [m]
rm = 0.0245;    % motor arm length [m]
rb = 0.02;  % radius of the ball [m]
mb = 0.265;   % mass of the ball [kg]
Jb = 0.0000416; % rotarional inertia of the ball [kg * m^2]
g = 9.81;   % gravitational acceleration [m / s^2]
Km = 100;   % servomotor's gain
tau = 0.01; % servomotor's time constant

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
