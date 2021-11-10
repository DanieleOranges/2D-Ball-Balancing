close all
clear all
clc

addpath('..\Models\')
set(0, 'DefaultFigureWindowStyle', 'docked')
data


load('lab05.mat');
%% Data_definition

% indexes of tests from 0
i_start_up = [2074 9319 16024;...
              7385 14324 22207;...
              2960 10056 18044;...
              1659 7101 13448;...
              2558 8786 15165;...
              4612 8711 11861;...
              4479 10703 15212];


% indexes of tests to 0
i_start_dw = [5870 12772 19317;...
               10366 18488 25400;...
               6250 14698 25218;...
               4851 10604 16648;...
               6016 11833 17883;...
               6210 10461 12694;...
               8433 13680 17220];

T_end_idx = T_end*100; 
dt = 0.01; 
time = 0:dt:T_end; 
   
% PID indexes of the tests
PID_idx = [1 2 3 7 6 1 2];  

% References for the tests  
ref_x = [0.09 0.09 0.09 0.09 0.09 0    0   ];
ref_y = [0    0    0    0    0    0.06 0.06];

%% Tests Averaging


for ii = 1:length(PID_idx)
    

     avg_test(ii).up.X  = mean([test(ii).X(i_start_up(ii, 1):i_start_up(ii, 1)+T_end_idx)'; ...
                                test(ii).X(i_start_up(ii, 2):i_start_up(ii, 2)+T_end_idx)'; ... 
                                test(ii).X(i_start_up(ii, 3):i_start_up(ii, 3)+T_end_idx)']);
 
     avg_test(ii).up.Y  = mean([test(ii).Y(i_start_up(ii, 1):i_start_up(ii, 1)+T_end_idx)'; ...
                                test(ii).Y(i_start_up(ii, 2):i_start_up(ii, 2)+T_end_idx)'; ... 
                                test(ii).Y(i_start_up(ii, 3):i_start_up(ii, 3)+T_end_idx)']);
        

     avg_test(ii).up.Vx = mean([test(ii).motX(i_start_up(ii, 1):i_start_up(ii, 1)+T_end_idx)'; ...
                                test(ii).motX(i_start_up(ii, 2):i_start_up(ii, 2)+T_end_idx)'; ... 
                                test(ii).motX(i_start_up(ii, 3):i_start_up(ii, 3)+T_end_idx)']);
    

     avg_test(ii).up.Vy = mean([test(ii).motY(i_start_up(ii, 1):i_start_up(ii, 1)+T_end_idx)'; ...
                                test(ii).motY(i_start_up(ii, 2):i_start_up(ii, 2)+T_end_idx)'; ... 
                                test(ii).motY(i_start_up(ii, 3):i_start_up(ii, 3)+T_end_idx)']);



     avg_test(ii).dw.X  = mean([test(ii).X(i_start_dw(ii, 1):i_start_dw(ii, 1)+T_end_idx)'; ...
                                test(ii).X(i_start_dw(ii, 2):i_start_dw(ii, 2)+T_end_idx)'; ... 
                                test(ii).X(i_start_dw(ii, 3):i_start_dw(ii, 3)+T_end_idx)']);
 
     avg_test(ii).dw.Y  = mean([test(ii).Y(i_start_dw(ii, 1):i_start_dw(ii, 1)+T_end_idx)'; ...
                                test(ii).Y(i_start_dw(ii, 2):i_start_dw(ii, 2)+T_end_idx)'; ... 
                                test(ii).Y(i_start_dw(ii, 3):i_start_dw(ii, 3)+T_end_idx)']);
    

     avg_test(ii).dw.Vx = mean([test(ii).motX(i_start_dw(ii, 1):i_start_dw(ii, 1)+T_end_idx)'; ...
                                test(ii).motX(i_start_dw(ii, 2):i_start_dw(ii, 2)+T_end_idx)'; ... 
                                test(ii).motX(i_start_dw(ii, 3):i_start_dw(ii, 3)+T_end_idx)']);
    

     avg_test(ii).dw.Vy = mean([test(ii).motY(i_start_dw(ii, 1):i_start_dw(ii, 1)+T_end_idx)'; ...
                                test(ii).motY(i_start_dw(ii, 2):i_start_dw(ii, 2)+T_end_idx)'; ... 
                                test(ii).motY(i_start_dw(ii, 3):i_start_dw(ii, 3)+T_end_idx)']);


    avg_test(ii).time = 0:0.01:T_end; 
    
    % Vectors for fitting
    Xexp{ii} = [avg_test(ii).time', avg_test(ii).up.X'];

    Yexp{ii} = [avg_test(ii).time', avg_test(ii).up.Y'];
    

%     figure
%     hold on 
%     plot(avg_test(ii).time, test(ii).motX(i_start_up(ii, 1):i_start_up(ii, 1)+T_end_idx)')
%     plot(avg_test(ii).time, test(ii).motX(i_start_up(ii, 2):i_start_up(ii, 2)+T_end_idx)')
%     plot(avg_test(ii).time, test(ii).motX(i_start_up(ii, 3):i_start_up(ii, 3)+T_end_idx)')
%     plot(avg_test(ii).time', avg_test(ii).up.Vx', 'nleWidth', 1.5)
end




%% X axis tests
for ii = 1:5
    
    % Parameter definition
    PID_sim = PID(PID_idx(ii)); 
    IC        = [-0.005 0.0];    
    ref.x.v = ref_x(ii)*ones(length(time),1);
    ref.x.t = time;
    ref.y.v = ref_y(ii)*ones(length(time),1);
    ref.y.t = time;
    bias_Vx = 0.054595;

    % Simulation
    nl  = sim('non_linear_sys.slx');
    lin = sim('linear_sys.slx');

    
    % Position plot
    figure
    subplot(2,1,1)
    hold on 
    plot(ref.x.t, ref.x.v, '--k')
    plot(avg_test(ii).time, avg_test(ii).up.X, 'LineWidth', 1.2)
    plot(lin.x)
    plot(nl.x)
    ylabel('X [m]')
    xlabel('T [s]')
    title(['test no', num2str(ii)])
    legend('ref','average', 'linear sys', 'non linear sys')
    
    % Voltage plot
    subplot(2,1,2)
    hold on 
    plot(ref.y.t, ref.y.t./ref.y.t * bias_Vy, '--k')    
    plot(avg_test(ii).time, avg_test(ii).up.Vx, 'LineWidth', 1.2)
    plot(lin.Vx)
    plot(nl.Vx)
    ylabel('Vx [m]')
    xlabel('T [s]')
    legend('average', 'linear sys', 'non linear sys')
    

end


for ii = 6:7
   
    % Parameter definition
    PID_sim = PID(PID_idx(ii)); 
    IC        = [0.0 0.0];    
    ref.x.v = ref_x(ii)*ones(length(time),1);
    ref.x.t = time;
    ref.y.v = ref_y(ii)*ones(length(time),1);
    ref.y.t = time;
    bias_Vy = 0.19216;

    % Simulation
    nl  = sim('non_linear_sys.slx');
    lin = sim('linear_sys.slx');

    % Position plot
    figure
    subplot(2,1,1)
    hold on 
    plot(ref.y.t, ref.y.v, '--k')    
    plot(avg_test(ii).time, avg_test(ii).up.Y, 'LineWidth', 1.2)
    plot(lin.y)
    plot(nl.y)
    ylabel('Y [m]')
    xlabel('T [s]')
    title(['test no', num2str(ii)])
    legend('ref', 'average', 'linear sys', 'non linear sys')

    % Voltage plot
    subplot(2,1,2)
    hold on 
    plot(ref.x.t, ref.x.t./ref.x.t * bias_Vx, '--k')    
    plot(avg_test(ii).time, avg_test(ii).up.Vy, 'LineWidth', 1.2)
    plot(lin.Vy)
    plot(nl.Vy)
    ylabel('Vy [m]')
    xlabel('T [s]')
    legend('average', 'linear sys', 'non linear sys')
end



%% Parameter Estimation SETUP

ii = 4;

IC        = [0 0.0];    
ref.x.v = ref_x(ii)*ones(length(time),1);
ref.x.t = time;
ref.y.v = ref_y(ii)*ones(length(time),1);
ref.y.t = time;
PID_sim = PID(ii); 

XE = Xexp{ii};
YE = Yexp{ii}; 
