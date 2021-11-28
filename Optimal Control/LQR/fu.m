function Out = fu(u,varargin)

sys_data()

ux = u(1);
uy = u(2);

if nargin > 1
    ux = u(1,:);
    uy = u(2,:);
    T = varargin{1};
    time = varargin{2};
    ux = interp1(time,ux,T); 
    uy = interp1(time,uy,T);
end

Out = zeros(4,2);
Out(1,1) = Kbbx*cos(ux);
Out(3,2) = Kbby*cos(uy); 