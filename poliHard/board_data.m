%% Init
clear
clc
addpath('script')
current = pwd; 

%% Import Control Data

cd('..\')
control_data
cd(current)

circ1   = monza; 

%% Touch touchersion

serial_freq = 50; 

touch.x.real = [-0.17 -0.15 -0.1 -0.05 0   0.05 0.1 0.15 0.17];  
touch.x.raw  = [95     123   226  350  478 585  705 844  880 ];

touch.y.real = [-0.13 -0.1 -0.05 0   0.05 0.1 0.13];     
touch.y.raw  = [152    226  360  484 623  760 851 ];

touch.x.poly = polyfit(touch.x.raw, touch.x.real, 1);
touch.y.poly = polyfit(touch.y.raw, touch.y.real, 1);

touch.x.gain = touch.x.poly(1);
touch.x.bias = touch.x.poly(2);

touch.y.gain = touch.y.poly(1);
touch.y.bias = touch.y.poly(2);

conv_scope_x = @(z) polyval(touch.x.poly, z); 
conv_scope_y = @(z) polyval(touch.y.poly, z); 


% Total dimensions [m]
x_min  = - 0.374/2;
x_max  =   0.374/2;
y_min  = - 0.307/2;
y_max  =   0.307/2;
border =   0.01; 

th_min =  -pi/2; 
th_max =   pi/2; 
%% Motor touchersion

% load('gain_matrix.mat')

pwm.thX.real = [pi/2 -pi/2];  
pwm.thX.raw  = [0 5400]-500;

pwm.thY.real = [pi/2 -pi/2];     
pwm.thY.raw  = [0 5400]-500;

% raw2real
pwm.thX.raw2real_poly = polyfit(pwm.thX.raw, pwm.thX.real, 1);
pwm.thY.raw2real_poly = polyfit(pwm.thY.raw, pwm.thY.real, 1);

conv_scope_thX = @(z) polyval(pwm.thX.raw2real_poly, z); 
conv_scope_thY = @(z) polyval(pwm.thY.raw2real_poly, z); 

% real2raw
pwm.thX.real2raw_poly = polyfit(pwm.thX.real, pwm.thX.raw, 1);
pwm.thY.real2raw_poly = polyfit(pwm.thY.real, pwm.thY.raw, 1);

pwm.thX.real2raw_gain = pwm.thX.real2raw_poly(1);
pwm.thX.real2raw_bias = pwm.thX.real2raw_poly(2);

pwm.thY.real2raw_gain = pwm.thY.real2raw_poly(1);
pwm.thY.real2raw_bias = pwm.thY.real2raw_poly(2);



save('..\ScopeData');%, 'conv_scope_x', 'conv_scope_y', 'conv_scope_thX', 'conv_scope_thY')