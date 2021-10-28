function dx = stateEq(t,x,u,time)
Kbbx = 1.2070;
Kbby = 0.9381;

dx = zeros(4,1);
ux = interp1(time,u(1,:),t); % Interpolate the control at time t
uy = interp1(time,u(2,:),t);

dx(1) = x(2);
dx(2) = Kbbx*(ux);
dx(3) = x(4);
dx(4) = Kbby*(uy);

