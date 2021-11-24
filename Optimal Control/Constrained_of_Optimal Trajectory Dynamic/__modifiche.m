MAIN
[xGrid,yGrid] = meshgrid(time,1:ii-1);
figure; mesh(xGrid,yGrid,abs(DHx)); hold on; 
xlabel('time [s]'); ylabel('iterations'); zlabel('|dH/du|'); title('x direction error')
figure; mesh(xGrid,yGrid,abs(DHy)); hold on; 
xlabel('time [s]'); ylabel('iterations'); zlabel('|dH/du|'); title('y direction error')

stateEq
dx(1) = Kbbx*sin(K/tau*(K+1)*exp(-t/tau)*ux);

pH
dH(1,:) = Lu(1) + p2.*K/tau*(K+1).*exp(-Tu/tau).*Kbbx.*cos(K/tau*(K+1).*exp(-Tu/tau).*ux);
