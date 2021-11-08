function dp = adjointEq(t,p,u,Tu,x1,x2,x3,x4,ref,xt,R)

dp = zeros(4,1);
x1 = interp1(xt,x1,t);   % Interpolate the state variables
x2 = interp1(xt,x2,t);
x3 = interp1(xt,x3,t);
x4 = interp1(xt,x4,t);

ref.x = interp1(xt,ref.x,t);
ref.y = interp1(xt,ref.y,t);
ux = interp1(Tu,u(1,:),t);     % Interpolate the control
uy = interp1(Tu,u(2,:),t);

Lx = [ R(1,1)*(x1-ref.x);
                  0;
       R(3,3)*(x3-ref.y);
                 0];

A  = [0,1,0,0;   % x1
      0,0,0,0;   % x2
      0,0,0,1;   % x3
      0,0,0,0];  % x4

% Adjoint Equation: lambdap = -(Lx + lambda'*A)' || A = df/dx || Lx = dJ/dx
dp = -(Lx' + p'*A)';

