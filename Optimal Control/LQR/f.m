function dx = f(t,x,c,Tc)

sys_data()

dx = zeros(4,1);

ux = c(1,:);
uy = c(2,:);
ux = interp1(Tc,ux,t); 
uy = interp1(Tc,uy,t);

dx(1) = Kbbx*sin(ux);
dx(2) = x(1);
dx(3) = Kbby*sin(uy);
dx(4) = x(3);