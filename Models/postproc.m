close all
clear all
clc

data

sim('multibody_sys.slx')
multi = ans;
sim('linear_sys.slx')
lin = ans; 
sim('non_linear_sys.slx')
nl = ans; 

%%

figure
subplot(2,1,1)
hold on 
plot(ref.x.t, ref.x.v)
plot(multi.x)
plot(lin.x)
plot(nl.x)
ylabel('X [m]')
xlabel('T [s]')
legend('ref_X','Multibody', 'Linear', 'Non-Linear')

subplot(2,1,2)
hold on 
plot(ref.y.t, ref.y.v)
plot(multi.y)
plot(lin.y)
plot(nl.y)
ylabel('Y [m]')
xlabel('T [s]')
legend('ref_Y','Multibody', 'Linear', 'Non-Linear')

