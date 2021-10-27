function u_new = iterControl(pH_old,pH,tx,u,tu,step)
% interpolate dH/du
pHx = interp1(tx,pH(1,:),tu);
pHy = interp1(tx,pH(2,:),tu);

% pH_oldx = interp1(tx,pH_old(1,:),tu);
% pH_oldy = interp1(tx,pH_old(2,:),tu);

% variable step !!BEWARE!!
% step = step + (pH - pH_old)/norm(pH - pH_old)*step;

u_new = u - step.*[pHx;pHy];