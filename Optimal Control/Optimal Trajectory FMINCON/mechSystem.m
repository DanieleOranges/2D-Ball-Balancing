function [dx,fx,fu] = mechSystem()

% Data:
Kbbx = 1.2070;
Kbby = 0.9381;

% Dynamical system
dx = @(x,u) [ Kbbx*(u(1));
                     x(1);
              Kbby*(u(2));            
                     x(3)];

% Jacobian of the dynamics
fx = @(x,u) [  0 , 0 , 0 , 0;  
               1 , 0 , 0 , 0;          
               0 , 0 , 0 , 0;          
               0 , 0 , 1 , 0];         
     
fu = @(x,u) [        1*Kbbx,               0; 
                          0,               0;
                          0,          1*Kbby;
                          0,              0];