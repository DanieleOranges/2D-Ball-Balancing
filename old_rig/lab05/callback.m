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






% A = 0.03; 
% ref_2 = [0 0]; 

% frequency = 0.1;
% 
% 
% time = 0:0.01:100;
% 
% ref.x.v = A*sin(2*pi*frequency*time);
% ref.x.t = time;
% ref.y.v = A*sin(2*pi*frequency*time + pi/2);
% ref.y.t = time;
% ref.x.v = 0*time + 0.06;
% ref.x.t = time;
% ref.y.v = 0*time;
% ref.y.t = time+ 0.06;

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
% 
ref_2 = [0 0]; 
ref_3 = [0 0.06];

%

Xtare_real =  [-127.5 -80 0 80 127.5] * 1e-3;
Xtare_raw  =  [870 1250 2036 2836 3410];


Ytare_real =  [-97.5 -50 0 50 110]*1e-3; 
Ytare_raw  =  [890 1370 2040 2690 3409]; 




%% PID
% 
% Trovato sperimentalmente con Daniele
PID(1).x.Kp     = 18.57;
PID(1).x.Ki     = 3;
PID(1).x.Kd     = 21.6;
PID(1).x.filter = 10;
PID(1).y = PID(1).x;

% X con 18° e 5 rad/s balanced
PID(2).x.Kp     = 56.5;
PID(2).x.Ki     = 2.4;
PID(2).x.Kd     = 29.4;
PID(2).x.filter = 52;

PID(2).y.Kp     = 49.9;
PID(2).y.Ki     = 2.14;
PID(2).y.Kd     = 22.86;
PID(2).y.filter = 52;

% X con 25° e 5 rad/s balanced
PID(3).x.Kp     = 37.6;
PID(3).x.Ki     = 1.58;
PID(3).x.Kd     = 30.9;
PID(3).x.filter = 52;

PID(3).y.Kp     = 35.1;
PID(3).y.Ki     = 1.49;
PID(3).y.Kd     = 24.16;
PID(3).y.filter = 52;

PID(4).x.Kp     = 22.5;
PID(4).x.Ki     = 0.2; 
PID(4).x.Kd     = 18;
PID(4).x.filter = 20; 
PID(4).y = PID(4).x;

% bw 3.8 pm 34
PID(5).x.Kp     = 12.53 ;
PID(5).x.Ki     = 1.44  ;
PID(5).x.Kd     = 23.19 ;
PID(5).x.filter = 20.73 ;
PID(5).y = PID(5).x;

PID(6).x.Kp     = 19.3;
PID(6).x.Ki     = 3.55;
PID(6).x.Kd     = 25.82;
PID(6).x.filter = 44.06;
PID(6).y = PID(6).x;

PID_sim = PID(6); 

% PID(8).x.Kp     = 37.6;
% PID(8).x.Ki     = 1.58;
% PID(8).x.Kd     = 30.9;
% PID(8).x.filter = 28;
% 
% PID(8).y = PID(8).x;

PID_sim = PID(3); 

% PID_sim.td = PID_sim.Kd/ PID_sim.Kp;
% PID_sim.ti = PID_sim.Kp/(PID_sim.Ki);