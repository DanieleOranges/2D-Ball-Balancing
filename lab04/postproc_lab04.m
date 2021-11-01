close all
clear all
clc

addpath('..\Models\')
set(0, 'DefaultFigureWindowStyle', 'docked')
data


load('lab04.mat');
%%

i_start = [0 0 0 0 17443];

IC        = [0.0 0.0];     

PID_idx = [12 12 12 12 12 ];

%%

ref.x.v = 0.09*ones(length(time),1);
ref.x.t = time;
ref.y.v = 0.07*ones(length(time),1);
ref.y.t = time;


for ii = 5:5%1:length(test)
    PID_sim = PID(PID_idx(ii)); 

% sim('multibody_sys.slx')
% % multi = ans;
sim('linear_sys.slx')
lin = ans; 
% sim('non_linear_sys.slx')
% nl = ans; 

figure
subplot(2,2,1)
hold on 
plot(ref.x.t, ref.x.v)
% plot(multi.x)
plot(lin.x)
% plot(nl.x)
plot(test(ii).t(i_start(ii):i_start(ii)+T_end*100)-test(ii).t(i_start(ii)), test(ii).X(i_start(ii):i_start(ii)+T_end*100))
ylabel('X [m]')
xlabel('T [s]')
legend('ref_X','Multibody', 'Linear', 'Non-Linear', 'real')


subplot(2,2,3)
hold on 
plot(ref.y.t, ref.y.v)
% plot(multi.y)
plot(lin.y)
% plot(nl.y)
plot(test(ii).t(i_start(ii):i_start(ii)+T_end*100)-test(ii).t(i_start(ii)), test(ii).Y(i_start(ii):i_start(ii)+T_end*100))
ylabel('Y [m]')
xlabel('T [s]')
legend('ref_Y','Multibody', 'Linear', 'Non-Linear','real')

subplot(2,2,2)
hold on 
% plot(multi.Vx)
plot(lin.Vx)
% plot(nl.Vx)
plot(test(ii).t(i_start(ii):i_start(ii)+T_end*100)-test(ii).t(i_start(ii)), test(ii).motX(i_start(ii):i_start(ii)+T_end*100))
ylabel('Vx [m]')
xlabel('T [s]')
legend('Multibody', 'Linear', 'Non-Linear', 'real')

subplot(2,2,4)
hold on 
% plot(multi.Vy)
plot(lin.Vy)
% plot(nl.Vy)
plot(test(ii).t(i_start(ii):i_start(ii)+T_end*100)-test(ii).t(i_start(ii)), test(ii).motY(i_start(ii):i_start(ii)+T_end*100))
ylabel('Vy [m]')
xlabel('T [s]')
legend('Multibody', 'Linear', 'Non-Linear', 'real')
clear multi lin nl ans
end
