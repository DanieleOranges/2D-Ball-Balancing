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

figure(1)
subplot(2,1,1)
hold on 
plot(multi.REF_X)
plot(multi.x)
plot(lin.x)
plot(nl.x)
ylabel('X [m]')
xlabel('T [s]')
legend('ref_X','Multibody', 'Linear', 'Non-Linear')

subplot(2,1,2)
hold on 
plot(multi.REF_Y)
plot(multi.y)
plot(lin.y)
plot(nl.y)
ylabel('Y [m]')
xlabel('T [s]')
legend('ref_Y','Multibody', 'Linear', 'Non-Linear')

%%
% figure(2)
% 
% subplot(2,2,1)
% hold on 
% plot(multi.motY.Time,rad2deg(multi.motY.Data))
% plot(lin.betha.Time,rad2deg(lin.betha.Data))
% %plot(nl2.betha.Time,rad2deg(nl2.betha.Data))
% ylabel('bheta [rad]')
% xlabel('T [s]')
% legend('Multibody', 'lin&Non-Linear')
% 
% subplot(2,2,3)
% hold on 
% plot(multi.motX.Time,rad2deg(multi.motX.Data))
% plot(lin.alpha.Time,rad2deg(lin.alpha.Data))
% %plot(nl2.alpha.Time,rad2deg(nl2.alpha.Data))
% ylabel('alpha [rad]')
% xlabel('T [s]')
% legend('Multibody', 'lin&Non-Linear')
% 
% subplot(2,2,2)
% hold on 
% plot(multi.ThetaX.Time,rad2deg(multi.ThetaX.Data))
% plot(lin.ThetaX.Time,rad2deg(lin.ThetaX.Data))
% %plot(nl2.ThetaX.Time,rad2deg(nl2.ThetaX.Data))
% ylabel('ThetaX [rad]')
% xlabel('T [s]')
% legend('Multibody', 'lin&Non-Linear')
% 
% subplot(2,2,4)
% hold on 
% plot(multi.ThetaY.Time,rad2deg(multi.ThetaY.Data))
% plot(lin.ThetaY.Time,rad2deg(lin.ThetaY.Data))
% %plot(nl2.ThetaY.Time,rad2deg(nl2.ThetaY.Data))
% ylabel('ThetaY [rad]')
% xlabel('T [s]')
% legend('Multibody', 'lin&Non-Linear')
%%

n_stap=50;
T1=ceil(linspace(0,size(multi.REF_X.Time,1),n_stap));
T2=ceil(linspace(0,size(multi.x.Time,1),n_stap));
T3=ceil(linspace(0,size(lin.x.Time,1),n_stap));
T4=ceil(linspace(0,size(nl.x.Time,1),n_stap));
T5=ceil(linspace(0,size(nl2.x.Time,1),n_stap));
for i=1:n_stap
figure(3)
hFig=figure(3);
set(0,'DefaultFigureUnits', 'normalized', 'DefaultFigurePosition', [0 0 1 0.8]);
hold on 
plot(multi.REF_X.Data([1:T1(i)]),multi.REF_Y.Data([1:T1(i)]))
plot(multi.x.Data([1:T2(i)]),multi.y.Data([1:T2(i)]))
plot(lin.x.Data([1:T3(i)]),lin.y.Data([1:T3(i)]))
plot(nl.x.Data([1:T4(i)]),nl.y.Data([1:T4(i)]))
plot(nl2.x.Data([1:T5(i)]),nl2.y.Data([1:T5(i)]))
ylabel('Y [m]')
xlabel('X [m]')
legend('ref_X','Multibody', 'Linear', 'Non-Linear','Non-Linear_2')
axis([-0.15 0.15 -0.2 0.2])
pause(0.01)
end

