close all
clear all
clc

set(0, 'DefaultFigureWindowStyle', 'docked')
data


%%


IC        = [0.0 0.0];     



PID_idx = [2 5];
n = length(PID_idx);
%%
ref_x = 0.08;
ref_y = 0.08;
    
    ref.x.v = ref_x*ones(length(time),1);
    ref.x.t = time;
    ref.y.v = ref_y*ones(length(time),1);
    ref.y.t = time;


%     ref.x.v = ref_x*sin(2*pi*0.2*time);
%     ref.x.t = time;
%     ref.y.v = ref_y*sin(2*pi*0.2*time + pi/2);
%     ref.y.t = time;

figure
    hold on 
    plot(ref.x.t, ref.x.v)

    leg_entry{1} = 'ref';

for ii = 1:n
        leg_entry{ii+1} = num2str(PID_idx(ii));

    PID_sim = PID(PID_idx(ii)); 

    

    sim('linear_sys.slx')
    ans.Vx = ans.Vx + bias_Vx; 
    ans.Vy = ans.Vy + bias_Vy; 
    lin(ii) = ans; 



    plot(lin(ii).x)
    ylabel('X [m]')
    xlabel('T [s]')
    
    
%     subplot(2,2,3)
%     hold on 
%     plot(ref.y.t, ref.y.v)
%     plot(multi.y)
%     plot(lin.y)
%     plot(nl.y)
%     plot(test(ii).t(i_start(ii):i_start(ii)+T_end*100)-test(ii).t(i_start(ii)), test(ii).Y(i_start(ii):i_start(ii)+T_end*100))
%     ylabel('Y [m]')
%     xlabel('T [s]')
%     legend('ref_Y','Multibody', 'Linear', 'Non-Linear','real')
%     
%     
%     subplot(2,2,2)
%     hold on 
%     plot(multi.Vx)
%     plot(lin.Vx)
%     plot(nl.Vx)
%     plot(test(ii).t(i_start(ii):i_start(ii)+T_end*100)-test(ii).t(i_start(ii)), test(ii).motX(i_start(ii):i_start(ii)+T_end*100))
%     ylabel('Vx [m]')
%     xlabel('T [s]')
%     legend('Multibody', 'Linear', 'Non-Linear', 'real')
%     
%     
%     subplot(2,2,4)
%     hold on 
%     plot(multi.Vy)
%     plot(lin.Vy)
%     plot(nl.Vy)
%     plot(test(ii).t(i_start(ii):i_start(ii)+T_end*100)-test(ii).t(i_start(ii)), test(ii).motY(i_start(ii):i_start(ii)+T_end*100))
%     ylabel('Vy [m]')
%     xlabel('T [s]')
%     legend('Multibody', 'Linear', 'Non-Linear', 'real')
%     clear multi lin nl ans
end
legend(leg_entry)
