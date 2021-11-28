clear
clc
close all
set(0,'DefaultFigureWindowStyle','docked')
addpath Piste\

t0 = 10;
dt = 2;
t  = t0:-dt:2;
fval = zeros(length(t),1);
for ii = 1 : length(t)
    disp(strcat('Iteration: ',num2str(ii)))
    disp(strcat('Remaining Iterations:',num2str(length(t)-ii)))
    tic
    [fval(ii),results(ii)] = OpenEndOptimalControl(t(ii));
    solver_time = toc;
    disp(strcat('Remaining time',num2str(solver_time*(length(t)-ii))))
end

%% Saving results
save('OpenEndResults.mat',"fval","results");

%% Plot

% Trajectory
close all
figure; hold on; grid on;
title('$Trajectory Comparison$','interpreter','latex');
xlabel('$X Position [m]$','Interpreter','latex');
ylabel('$Y Position [m]$','Interpreter','latex');
for ii = 1:length(fval)
    plot(results(ii).x(2,:),results(ii).x(4,:))
end
[~,ii]= min(fval);
h1 = plot(results(1).xref(2,:),results(1).xref(4,:),'b','LineWidth',2);
h2 = plot(results(ii).x(2,:),results(ii).x(4,:),'k','LineWidth',2);
h3 = plot(results(end).x(2,:),results(end).x(4,:),'r','LineWidth',2);
legend([h1,h2,h3],{'Reference' ...
                   strcat('Optimal time: ',num2str(t(ii))), ...
                   strcat('Minimum time: ',num2str(t(end)))});

% Control Effort
figure; hold on; grid on;
title('$Control Effort on X Comparison$','interpreter','latex');
xlabel('$time [s]$','Interpreter','latex');
ylabel('$Control Effort on X [deg]$','Interpreter','latex');
for ii = 1:length(fval)
    plot(results(ii).time(2:end),results(ii).u(1,:)*180/pi)
end
[~,ii]= min(fval);
h2 = plot(results(ii).time(2:end),results(ii).u(1,:)*180/pi,'k','LineWidth',2);
h3 = plot(results(end).time(2:end),results(end).u(1,:)*180/pi,'r','LineWidth',2);
legend([h2,h3],{strcat('Optimal time: ',num2str(t(ii))), ...
                strcat('Minimum time: ',num2str(t(end)))});

% Cost Functional
figure; hold on; grid on;
plot(t,fval);
title('$Cost functional Variation$','Interpreter','latex')
xlabel('$Time [s]$','Interpreter','latex')
ylabel('$Cost functional$','Interpreter','latex')
