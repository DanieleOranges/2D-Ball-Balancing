function dx = f(t,x,c,Tc)

global L w0 zeta m

dx = zeros(2,1);
u = interp1(Tc,c,t); % Interploate the control at time t

dx(1) = - 2*zeta*w0*x(1) - w0^2*sin(x(2)) + u/L^2/m;
dx(2) = x(1);