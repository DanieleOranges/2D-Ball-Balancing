function xp = stateEq(t,time,x,u,obj)

Kbbx = obj.Kbbx;
Kbby = obj.Kbby;
ux   = interp1(time,u(1,:),t);
uy   = interp1(time,u(1,:),t);

xp = [ Kbbx*ux;         
             0;
       Kbby*uy;
             0];


