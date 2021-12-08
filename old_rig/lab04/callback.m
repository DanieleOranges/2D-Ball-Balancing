%% Callback for simulation


%% Data conversion plate
% Raw max/min from acquisition
Xmax_raw = 3423;
Xmin_raw = 868;

Ymax_raw = 3407;
Ymin_raw = 879;

% max/min real
Xmax = 0.150;
Xmin = -0.150;

Ymax = 0.100;
Ymin = -0.100;


Px = polyfit([Xmin_raw, Xmax_raw], [Xmin, Xmax], 1);
Xgain   = Px(1); 
Xoffset = Px(2); 

Py = polyfit([Ymin_raw, Ymax_raw], [Ymin, Ymax], 1);
Ygain   = Py(1); 
Yoffset = Py(2);

%% Data conversion plate
% Raw max/min from acquisition
T1max_raw = 4095;
T1min_raw = 0;

T2max_raw = 4095;
T2min_raw = 0;

% max/min real
T1max = 10;
T1min = -10;

T2max = 10;
T2min = -10;



Pt1 = polyfit([T1min, T1max], [T1min_raw, T1max_raw], 1);
T1gain   = Pt1(1); 
T1offset = Pt1(2);   

Pt2 = polyfit([T2min, T2max], [T2min_raw, T2max_raw], 1);
T2gain   = Pt2(1); 
T2offset = Pt2(2);

ref_2 = [0 0]; 
ref_3 = [0.09 0.07];

%

Xtare_real =  [-127.5 -80 0 80 127.5] * 1e-3;
Xtare_raw  =  [870 1250 2036 2836 3410];


Ytare_real =  [-97.5 -50 0 50 110]*1e-3; 
Ytare_raw  =  [890 1370 2040 2690 3409]; 


%% PID
% 
PID(1).Kp     = 3;           
PID(1).Ki     = 2.4;         
PID(1).Kd     = 1.5;         
PID(1).filter = 4.5;

PID(2).Kp     = 1.90389213912358 ;
PID(2).Ki     = 0.330968409924509;
PID(2).Kd     = 2.70762690974303;
PID(2).filter = 4.5;

PID(3).Kp     = 0.9;
PID(3).Ki     = 0.256;
PID(3).Kd     = 27.1;
PID(3).filter = 6;

PID(4).Kp     = 30;
PID(4).Ki     = 6;
PID(4).Kd     = 20;
PID(4).filter = 5;

PID(5).Kp     = 30;
PID(5).Ki     = 5;
PID(5).Kd     = 20;
PID(5).filter = 5;

PID(6).Kp     = 30;
PID(6).Ki     = 3;
PID(6).Kd     = 25;
PID(6).filter = 5;


PID(7).Kp     = 1.95;
PID(7).Ki     = 0.04;
PID(7).Kd     = 21.15;
PID(7).filter = 5;



% bw3.518 pm78.3 buon       
PID(7).Kp     = 1.95;
PID(7).Ki     = 0.04;
PID(7).Kd     = 21.15;
PID(7).filter = 5;

%7 63.9 merda
PID(8).Kp     = 8.65;
PID(8).Ki     = 0.35;
PID(8).Kd     = 46.95;
PID(8).filter = 5;

% 3.857 40.5 merda 
PID(9).Kp     = 37.6051;
PID(9).Ki     = 15.4718;
PID(9).Kd     = 22.2032;
PID(9).filter = 5;

PID(10).Kp     = 18.57;
PID(10).Ki     = 1.59;
PID(10).Kd     = 21.6;
PID(10).filter = 579.09;

PID(11).Kp     = 18.57;
PID(11).Ki     = 1.59;
PID(11).Kd     = 21.6;
PID(11).filter = 10;

PID(12).Kp     = 18.57;
PID(12).Ki     = 3;
PID(12).Kd     = 21.6;
PID(12).filter = 10;

PID_sim = PID(12); 
PID_sim.td = PID_sim.Kd/ PID_sim.Kp;
PID_sim.ti = PID_sim.Kp/(PID_sim.Ki);