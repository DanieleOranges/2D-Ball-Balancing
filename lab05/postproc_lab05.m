close all
clear all
clc

addpath('..\Models\')
set(0, 'DefaultFigureWindowStyle', 'docked')
data


load('lab05.mat');
%%

i_start_up = [2074 9319 16024;...
              7385 14324 22207;...
              2960 10056 18044;...
              1659 7101 13448;...
              2558 8786 15165;...
              4612 8711 11861;...
              4479 10703 15212];

i_start_dw = [5870 12772 19317;...
               10366 18488 25400;...
               6250 14698 25218;...
               4851 10604 16648;...
               6016 11833 17883;...
               6210 10461 12694;...
               8433 13680 17220]

T_end_idx = T_end*100; 
dt = 0.01; 

IC        = [0.0 0.0];     

PID_idx = [1 2 3 7 6 1 2];  

%%T_end_idx)']);
ref_x = [0.09 0.09 0.09 0.09 0.09 0    0   ];
ref_y = [0    0    0    0    0    0.06 0.06];

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
    
    Xexp{ii} = [avg_test(ii).time', avg_test(ii).up.X'];

    Yexp{ii} = [avg_test(ii).time', avg_test(ii).up.Y'];
    

    figure
    hold on 
    plot(avg_test(ii).time, test(ii).motX(i_start_up(ii, 1):i_start_up(ii, 1)+T_end_idx)')
    plot(avg_test(ii).time, test(ii).motX(i_start_up(ii, 2):i_start_up(ii, 2)+T_end_idx)')
    plot(avg_test(ii).time, test(ii).motX(i_start_up(ii, 3):i_start_up(ii, 3)+T_end_idx)')
    plot(avg_test(ii).time', avg_test(ii).up.Vx', 'LineWidth', 1.5)
end

for ii = 1:5
        PID_sim = PID(PID_idx(ii)); 
%%
    IC        = [-0.005 0.0];    
    ref.x.v = ref_x(ii)*ones(length(time),1);
    ref.x.t = time;
    ref.y.v = ref_y(ii)*ones(length(time),1);
    ref.y.t = time;
    
  %%  

%     
%     sim('multibody_sys.slx')
%     ans.Vx = ans.Vx + bias_Vx; 
%     ans.Vy = ans.Vy + bias_Vy; 
%     multi = ans;
%     sim('linear_sys.slx')
%     ans.Vx = ans.Vx + bias_Vx; 
%     ans.Vy = ans.Vy + bias_Vy; 
%     lin = ans; 
    sim('linear_sys_est.slx')
%     ans.Vx = ans.Vx + bias_Vx; 
%     ans.Vy = ans.Vy + bias_Vy; 
    lin = ans; 
    
    
    figure
    subplot(2,2,1)
    hold on 
    plot(ref.x.t, ref.x.v)
    plot(lin.x)
    plot(avg_test(ii).time, avg_test(ii).up.X)
    ylabel('X [m]')
    xlabel('T [s]')
    title('up')
    legend('ref','lin', 'average')
    
    subplot(2,2,3)
    hold on 
    plot(lin.Vx)
    plot(avg_test(ii).time, avg_test(ii).up.Vx)
    ylabel('Vx [m]')
    xlabel('T [s]')
    title('up')
    legend('lin', 'average')
    

    IC        = [ref_x(ii) ref_y(ii)];    
    ref.x.v = 0*ones(length(time),1);
    ref.x.t = time;
    ref.y.v = 0*ones(length(time),1);
    ref.y.t = time;

    sim('non_linear_sys.slx')
%     ans.Vx = ans.Vx + bias_Vx; 
%     ans.Vy = ans.Vy + bias_Vy; 
    lin = ans; 
    
    subplot(2,2,2)
    hold on 
    plot(ref.x.t, ref.x.v)
    plot(lin.x)
    plot(avg_test(ii).time, avg_test(ii).dw.X)
    ylabel('X [m]')
    xlabel('T [s]')
    title('down')
    legend('ref','lin', 'average')
    
    
    subplot(2,2,4)
    hold on 
    plot(lin.Vx)
    plot(avg_test(ii).time, avg_test(ii).dw.Vx)
    ylabel('Vx [m]')
    xlabel('T [s]')
    title('down')
    legend('lin', 'average')
    
    
end


for ii = 6:7
        PID_sim = PID(PID_idx(ii)); 

    IC        = [0.0 0.0];    
    ref.x.v = ref_x(ii)*ones(length(time),1);
    ref.x.t = time;
    ref.y.v = ref_y(ii)*ones(length(time),1);
    ref.y.t = time;
    
    

    
%     sim('multibody_sys.slx')
%     ans.Vx = ans.Vx + bias_Vx; 
%     ans.Vy = ans.Vy + bias_Vy; 
%     multi = ans;
%     sim('linear_sys.slx')
%     ans.Vx = ans.Vx + bias_Vx; 
%     ans.Vy = ans.Vy + bias_Vy; 
%     lin = ans; 
    sim('linear_sys_est.slx')
%     ans.Vx = ans.Vx + bias_Vx; 
%     ans.Vy = ans.Vy + bias_Vy; 
    lin = ans; 
    
    
    figure
    subplot(2,2,1)
    hold on 
    plot(ref.y.t, ref.y.v)
    plot(lin.y)
    plot(avg_test(ii).time, avg_test(ii).up.Y)
    ylabel('Y [m]')
    xlabel('T [s]')
    title('up')
    legend('ref','lin', 'average')
    
    subplot(2,2,3)
    hold on 
    plot(lin.Vy)
    plot(avg_test(ii).time, avg_test(ii).up.Vy)
    ylabel('Vy [m]')
    xlabel('T [s]')
    title('up')
    legend('lin', 'average')
    

    IC        = [ref_x(ii) ref_y(ii)];    
    ref.x.v = 0*ones(length(time),1);
    ref.x.t = time;
    ref.y.v = 0*ones(length(time),1);
    ref.y.t = time;

    sim('non_linear_sys.slx')
%     ans.Vx = ans.Vx + bias_Vx; 
%     ans.Vy = ans.Vy + bias_Vy; 
    lin = ans; 
    
    subplot(2,2,2)
    hold on 
    plot(ref.y.t, ref.y.v)
    plot(lin.y)
    plot(avg_test(ii).time, avg_test(ii).dw.Y)
    ylabel('Y [m]')
    xlabel('T [s]')
    title('down')
    legend('ref','lin', 'average')
    
    
    subplot(2,2,4)
    hold on 
    plot(lin.Vy)
    plot(avg_test(ii).time, avg_test(ii).dw.Vy)
    ylabel('Vy [m]')
    xlabel('T [s]')
    title('down')
    legend('lin', 'average')
    
    
end



%%
ii = 4

    IC        = [-0.005 0.0];    
    ref.x.v = ref_x(ii)*ones(length(time),1);
    ref.x.t = time;
    ref.y.v = ref_y(ii)*ones(length(time),1);
    ref.y.t = time;

    PID_sim = PID(ii); 

    XE = Xexp{ii};
    YE = Yexp{ii}; 
    