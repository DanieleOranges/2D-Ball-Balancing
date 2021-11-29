function dx = f(t,x,u,T)

sys_data()

dx = zeros(4,1);

ux = u(1,:);
uy = u(2,:);
ux = interp1(T,ux,t); 
uy = interp1(T,uy,t);

dx(1) = Kbbx*sin(ux);
dx(2) = x(1);
dx(3) = Kbby*sin(uy);
dx(4) = x(3);