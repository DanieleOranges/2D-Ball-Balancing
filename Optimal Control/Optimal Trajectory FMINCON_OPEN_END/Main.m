clear all
clc
close all
set(0,'DefaultFigureWindowStyle','docked')

t0 = 20;
dt = 2;
t  = [t0:-dt:2];
for ii = 1 : length(t)
    disp(strcat('Iteration: ',num2str(ii)))
    disp(strcat('Remaining Iterations:',num2str(length(t)-ii)))
    tic
    [fval(ii),results(ii),time(ii,:)] = OpenEndOptimalControl(t(ii));
    solver_time = toc;
    disp(strcat('Remaining time',num2str(solver_time*(length(t)-ii))))
end
    
%% Plot
close all
figure; hold on; grid on;
title('$Trajectory Comparison$','interpreter','latex');
xlabel('$X Position [m]$','Interpreter','latex');
ylabel('$Y Position [m]$','Interpreter','latex');
for ii = 1:length(fval)
    plot(results(ii).x(2,:),results(ii).x(4,:))
end
[~,ii]= min(fval);
h2 = plot(results(ii).x(2,:),results(ii).x(4,:),'k','LineWidth',2);
legend(h2,strcat('Optimal time: ',num2str(t(ii))));

figure; hold on; grid on;
plot(fval);