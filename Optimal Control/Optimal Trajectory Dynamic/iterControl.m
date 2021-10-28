function u_new = iterControl(pH,tx,u,tu,step,pH_old)
% interpolate dH/du
pHx = interp1(tx,pH(1,:),tu);
pHy = interp1(tx,pH(2,:),tu);

% variable step implementation !!!!
% pH_oldx = interp1(tx,pH_old(1,:),tu);
% pH_oldy = interp1(tx,pH_old(2,:),tu);
% step = step*( 1 + 1*([pHx;pHy] - [pH_oldx;pH_oldy])/norm([pHx;pHy] - [pH_oldx;pH_oldy]));

u_new = u - step.*[pHx;pHy] ;