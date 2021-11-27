clear
clc
close all
set(0,'DefaultFigureWindowStyle','docked')

e0 = 0.05;
de = 0.01;
e  = e0:-de:0.01;
fval = zeros(length(e),1);
for ii = 1 : length(e)
    disp(strcat('Iteration: ',num2str(ii)))
    disp(strcat('Remaining Iterations:',num2str(length(e)-ii)))
    tic
    [fval(ii),results(ii)] = ErrorOptimalControl(e(ii));
    solver_time = toc;
    disp(strcat('Remaining time',num2str(solver_time*(length(e)-ii))))
end

%% Saving results
save('ErrorResults.mat',"fval","results");

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
h1 = plot(results(1).xref(2,:),results(1).xref(4,:),'m','LineWidth',3)
h2 = plot(results(ii).x(2,:),results(ii).x(4,:),'k','LineWidth',3);
h3 = plot(results(end).x(2,:),results(end).x(4,:),'r','LineWidth',3);
legend([h1,h2,h3],{'Reference' ...
                   strcat('Optimal error: ',num2str(e(ii))), ...
                   strcat('Minimum error: ',num2str(e(end)))});

% Control Effort
figure; hold on; grid on;
title('$Control Effort on X Comparison$','interpreter','latex');
xlabel('$time [s]$','Interpreter','latex');
ylabel('$Control Effort on X [deg]$','Interpreter','latex');
for ii = 1:length(fval)
    plot(results(ii).time(2:end),results(ii).u(1,:)*180/pi)
end
[~,ii]= min(fval);
h2 = plot(results(ii).time(2:end),results(ii).u(1,:)*180/pi,'k','LineWidth',3);
h3 = plot(results(end).time(2:end),results(end).u(1,:)*180/pi,'r','LineWidth',3);
legend([h2,h3],{strcat('Optimal error: ',num2str(e(ii))), ...
                strcat('Minimum error: ',num2str(e(end)))});

% Cost Functional
figure; hold on; grid on;
plot(e,fval);
title('$Cost functional Variation$','Interpreter','latex')
xlabel('$Error [~]$','Interpreter','latex')
ylabel('$Cost functional$','Interpreter','latex')
