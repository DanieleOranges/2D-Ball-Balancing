%%
figure(1)
X=out.x.data;
Y=out.y.data;
Z=out.z.data;
plot3(X, Z, Y)
figure(2)
hold on
plot(out.x,'b')
plot(out.y,'r')
plot(out.z,'g')
legend('x','y','z')
figure(3)
hold on
plot(out.Xplane,'b')
plot(out.Yplane,'r')
figure(4)
hold on
%plot(out.x.time,atan(out.x.data./out.y.data))
plot(out.angX,'b')
plot(out.angZ,'r')
%%
clc
X = deg2rad(linspace(0,30,5)');
Time = seconds(1:5);
TT = array2timetable(X,'RowTimes',Time)

%%
%beam
rm=2.45 ;           %(cm)  biella
lm=7.2 ;            %(cm)  manovella
d=2.1;              %(cm)   pezzo solidale al piano
R=0.5;              %(cm)   raggio delle aste
rho_beam=7500;      % (kg/m^3) densita delle aste
% motor joint
Mot_Osci_Rang=[-80 ,80];    %(deg)   range di oscilazione dei motori  

%plane
rho_plane=880;         %(kg/m^3) densita del piano
Lx=14.3;               %(cm)  
Ly=18.4;               %(cm)

%ball
rho_ball=8000;         % (kg/m^3) densita della sfera
R_ball=2;              % (cm) raggio della sfera
