function dx = f(t,x,c,Tc)

Kbbx = 1.207;
Kbby = 0.9381;
dx = zeros(4,1);

ux = c(1,:);
uy = c(2,:);
ux = interp1(Tc,ux,t); % Interploate the control at time t
uy = interp1(Tc,uy,t); % Interploate the control at time t

dx(1) = Kbbx*ux;
dx(2) = x(1);
dx(3) = Kbby*uy;
dx(4) = x(3);