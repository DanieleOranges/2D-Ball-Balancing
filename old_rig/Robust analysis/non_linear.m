%% Intro
close all
clear
clc
set(0,'DefaultFigureWindowStyle','docked')

% Data callback
data

pista = load('Monza.mat');

% Number of points for reference
Npts = 40;

ref.x.t = interp1(1:length(ref.x.t), ref.x.t, linspace(1, length(ref.x.t), Npts), 'nearest');
ref.y.t = interp1(1:length(ref.y.t), ref.y.t, linspace(1, length(ref.y.t), Npts), 'nearest');
ref.x.v = interp1(1:length(pista.x), pista.x, linspace(1, length(pista.x), Npts), 'nearest');
ref.y.v = interp1(1:length(pista.y), pista.y, linspace(1, length(pista.y), Npts), 'nearest');

% Non linear simulation
out = sim('non_linear_sys.slx');

%% Plots
figure(1); plot(out.x.Data,out.xp.Data,'b'); grid on; hold on
plot(out.y.Data,out.yp.Data,'r'); grid on
xlabel('Displacement');ylabel('Velocity')
title('Position state-space');legend('X','Y')

figure(2); scatter(out.x.Data,out.xp.Data,4,out.tout); grid on; colorbar(); hold on
scatter(out.y.Data,out.yp.Data,4,out.tout);
xlabel('Displacement');ylabel('Velocity')
title('Position state-space');legend('X','Y'); axis equal

figure(3); scatter(out.x.Data,out.y.Data,4,sqrt(out.xp.Data.^2+out.yp.Data.^2)); grid on; colorbar(); hold on
plot(ref.x.v,ref.y.v,'k')
axis equal
xlabel('X');ylabel('Y')
title('Trajectories')

figure(4); plot(out.theta_x); hold on; grid on; plot(out.theta_y)
title('Theta');legend('\Theta_X','\Theta_Y')
xlabel('Time');ylabel('Angle')