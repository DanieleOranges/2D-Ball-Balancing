%% Callback for simulation


%% Data conversion plate
% Raw max/min from acquisition
Xmax_raw = 3423;
Xmin_raw = 868;

Ymax_raw = 3407;
Ymin_raw = 879;

% max/min real
Xmax = 150;
Xmin = -150;

Ymax = 100;
Ymin = -100;


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
T1max = pi/2;
T1min = -pi/2;

T2max = pi/2;
T2min = -pi/2;



Pt1 = polyfit([T1min, T1max], [T1min_raw, T1max_raw], 1);
T1gain   = Pt1(1); 
T1offset = Pt1(2);   

Pt2 = polyfit([T2min, T2max], [T2min_raw, T2max_raw], 1);
T2gain   = Pt2(1); 
T2offset = Pt2(2);
% 