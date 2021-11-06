clear
clc
close all
set(0, 'DefaultFigureWindowStyle', 'docked')

txt2mat; 
callback;
P= polyfit([T1min_raw, T1max_raw],[T1min, T1max],  1);


for ii=1:length(test_raw)
    
    test(ii).X = interp1(Xtare_raw, Xtare_real, test_raw(ii).X);
    test(ii).Y = interp1(Ytare_raw, Ytare_real, test_raw(ii).Y); 
   
    test(ii).motX = polyval(P, test_raw(ii).motX);
    test(ii).motY = polyval(P, test_raw(ii).motY);

    test(ii).t = test_raw(ii).t;
    test(ii).name = test_raw(ii).name;


    
    figure
    subplot(3, 1, 1)
    scatter(test(ii).X, test(ii).Y)
    title('XYplot')
    xlabel('X [m]')
    ylabel('Y [m]')
    axis equal
    grid on 
%     
%     subplot(2, 2, 3)
%     plot(test(ii).Xreal, test(ii).Yreal)
%     title('XYplot new conversion')
%     xlabel('X [m]')
%     ylabel('Y [m]')
%     axis equal
%     grid on
%     
    subplot(3, 1, 2)
    hold on
    plot(test(ii).t, test(ii).X)
    plot(test(ii).t, test(ii).Y)
    title('Time plot SENSOR')
    xlabel('T [s]')
    ylabel('X/Y [m]')
    legend('X', 'Y')
    grid on 

    subplot(3, 1, 3)
    hold on
    plot(test(ii).t, test(ii).motX)
    plot(test(ii).t, test(ii).motY)
    title('Time plot MOTOR')
    xlabel('T [s]')
    ylabel('mot X/Y [m]')
    legend('motX', 'motY')
    grid on 
%     
%     subplot(2, 2, 4)
%     hold on
%     plot(test(ii).t, test(ii).Xreal)
%     plot(test(ii).t, test(ii).Yreal)
%     title('Time plot new conversion')
%     xlabel('T [s]')
%     ylabel('X/Y [m]')
%     legend('X', 'Y')
%     grid on
%     
%     saveas(gcf, ['figures\', num2str(ii), '.png'])
%     
end

save('lab05.mat', 'test')
%%


