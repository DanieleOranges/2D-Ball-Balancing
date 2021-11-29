figure; hold on; grid on; title('Trajectory Comparison','Interpreter','latex');
h1 = plot(x(2,:),x(4,:),'LineWidth',2); 
plot(x(2,:),x(4,:),'*b','LineWidth',2); 
plot(x(2,1),x(4,1),'*g','MarkerSize',12); axis equal
h2 = plot(xref(2,:),xref(4,:),'*k','LineWidth',2);
lgd = legend([h1,h2],{'$Trajectory$','$Reference$'},'Interpreter','LaTex');
xlabel('$X Position [m]$','Interpreter','latex')
ylabel('$Y Position [m]$','Interpreter','latex')

figure; hold on; grid on; title('$\|\varepsilon\|_2$','Interpreter','latex')
plot(t,err_norm)
xlabel('$Time [s]$','Interpreter','latex');
ylabel('$Error Norm_2$','Interpreter','latex');

figure; hold on; grid on; title('$Control Effort$','Interpreter','latex');
plot(t(2:end),u*180/pi);
xlabel('$Time [s]$','Interpreter','latex');
ylabel('$Control Effort [deg]$','Interpreter','latex');
legend('$U_x$','$U_y$','interpreter','latex')

figure; hold on; grid on; title('$Trajectory-Speed colorBox$','Interpreter','latex')
axis equal
scatter(x(2,:),x(4,:),16,vBall*1000,'filled');
cb = colorbar; cb.Label.Interpreter = 'latex';
cb.Label.String = ('$Ball speed [mm/s]$');
xlabel('$X Position [m]$','Interpreter','latex')
ylabel('$Y Position [m]$','Interpreter','latex')

figure; hold on; grid on; title('$Error Norm_2 colorBox$','Interpreter','latex')
axis equal
scatter(x(2,:),x(4,:),16,err_norm,'filled');
cb = colorbar; cb.Label.Interpreter = 'latex';
cb.Label.String = ('$Error Norm_2 [mm]$');
xlabel('$X Position [m]$','Interpreter','latex')
ylabel('$Y Position [m]$','Interpreter','latex')

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Animation ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ %
%%
animation_flag = 1;
if animation_flag == 1
    counter = 1;
    figure; hold on; grid on; axis equal; title('Real time Trajectory')
    xlim(2*[min(x(2,:)) max(x(2,:))])
    ylim(2*[min(x(4,:)) max(x(4,:))])
    pause(2)
    plot(xref(2,:),xref(4,:),'k','LineWidth',2);
    for ii = 1 : length(u)
        plot(x(2,ii),x(4,ii),'*g')
        h1(counter) = quiver(x(2,ii),x(4,ii), ...
                             x(1,ii),x(3,ii),'b');
        h2(counter) = quiver(x(2,ii),x(4,ii), ...
                             u(1,ii)*0.5,u(2,ii)*0.5,'r');
        pause(h); counter = counter + 1;
        if rem(ii,3) == 0
           for jj = 1 : counter-1
               h1(jj).Visible = 0;
               h2(jj).Visible = 0;
           end
           counter = 1;
        end

%     % Save Animation
%     frame = getframe();
%     im = frame2im(frame); 
%     [imind,cm] = rgb2ind(im,256); 
%     if ii==1
%      imwrite(imind,cm,'OptimalTrajectory.gif','gif','DelayTime',0.001, 'Loopcount',inf); 
%     else 
%      imwrite(imind,cm,'OptimalTrajectory.gif','gif','DelayTime',0.001,'WriteMode','append'); 
%     end   
    end
    clear h1
end