function dH = pH(x1,p1,x3,p3,tx,u,Tu,R)
% interpolate the control

Kbbx = 1.2070;
Kbby = 0.9381;

ux = interp1(Tu,u(1,:),tx);
uy = interp1(Tu,u(2,:),tx);

Lu = [0,0,0,0]';

dH(1,:) = Lu(1) + p1.*(Kbbx); % L_u + lmb^T*B (see the dynamic equation)
dH(2,:) = Lu(3) + p3.*(Kbby);
