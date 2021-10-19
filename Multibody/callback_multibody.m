%%
close all
clc
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
close all
clc

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
Lx=14.3;               %(cm)  posizione X della cerniera vanovella_piano
Ly=18.4 ;               %(cm)   posizione Y della cerniera vanovella_piano
Lx_plane=15;               %(cm)  dimensione X piano (met della lunghezza)
Ly_plane=20 ;              %(cm)  dimensione Y piano (met della lunghezza)

%ball
rho_ball=8000;         % (kg/m^3) densita della sfera
R_ball=2;              % (cm) raggio della sfera
X_start=0;             % (cm) posizione X di partenza della palla
Y_start=0;             % (cm) posizione Y di partenza della palla
Z_start=0;             % (cm) posizione X di partenza della palla (Z=0 palla e piano in contatto)

%cornice
Lx_cornice=15;         %(cm) dimensione X della cornice (meta)
Ly_cornice=20;         %(cm) dimensione Y della cornice (meta)
H_cornice=0.5;         %(cm) spessore cornice
W_cornice=2;           %(cm) altezza cornice

