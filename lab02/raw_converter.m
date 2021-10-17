clear
clc
close all
set(0, 'DefaultFigureWindowStyle', 'docked')

txt2mat_lab2; 
callback;

for ii=1:length(test_raw)
    test(ii).Xsim  = polyval(Px, test_raw(ii).X);
    test(ii).Ysim  = polyval(Py, test_raw(ii).Y);

    test(ii).Xreal = interp1(Xtare_raw, Xtare_real, test_raw(ii).X);
    test(ii).Yreal = interp1(Ytare_raw, Ytare_real, test_raw(ii).Y);    

    test(ii).t = test_raw(ii).t;
    test(ii).name = test_raw(ii).name;

%     figure
%     subplot(2, 2, 1)
%     plot(test(ii).Xsim, test(ii).Ysim)
%     title('XYplot old conversion')
%     xlabel('X [m]')
%     ylabel('Y [m]')
%     axis equal
%     grid on 
%     
%     subplot(2, 2, 3)
%     plot(test(ii).Xreal, test(ii).Yreal)
%     title('XYplot new conversion')
%     xlabel('X [m]')
%     ylabel('Y [m]')
%     axis equal
%     grid on
%     
%     subplot(2, 2, 2)
%     hold on
%     plot(test(ii).t, test(ii).Xsim)
%     plot(test(ii).t, test(ii).Ysim)
%     title('Time plot old conversion')
%     xlabel('T [s]')
%     ylabel('X/Y [m]')
%     legend('X', 'Y')
%     grid on 
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

save('lab2', 'test')
%%


