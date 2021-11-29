function [c,con,grad_nonlin,grad] = con_and_grad(z,param)

N   = param.N;
nx  = param.nx;
nu  = param.nu;
dx  = param.dx;
h   = param.h;
x_i = param.x_i;
t   = param.t;

%% State and control extraction from z
x = zeros(nx,N+1); u = zeros(nu,N);
for ii = 0:N
    x(:,ii+1) = z((1 + ii*(nu + nx)):(nx + ii*(nu + nx)));
end    
for ii = 0:N-1
    u(:,ii+1) = z((1 + nx + ii*(nu + nx)):(nx + nu + ii*(nu + nx)));    
end

%% Constraint inequality ~~~~~~~~~~~~~~~~~~~~ CONTROLLARE ~~~~~~~~~~~~~~~~~
lim = 1;
c = [];
% for ii = 1:N
%     c(1,:) = abs(diff(u(1,:),2)/h) > lim;  % Limit on control gradient
%     c(2,:) = abs(diff(u(2,:),2)/h) > lim;  % Limit on control gradient    
% end
% for ii = 0:N-1
%     c((1 + nx + ii*(nu + nx)):(nx + nu + ii*(nu + nx))) = u_constrain(:,ii+1); % u(:,ii+1) =    
% end
%% Constraint equality
con = zeros(N*nx,1);
con(1:nx) = x_i - x(:,1) ;  
for ii = 1:N
    con((1:nx) + ii*nx) = x(:,ii) + h*dx(x(:,ii),u(:,ii)) - x(:,ii+1);    
end

fx = param.fx;
fu = param.fu;

%% Gradients
if nargout > 2
grad_nonlin = [];  

grad = zeros(nx,N*(nu+nx) + nx); % gradient of a vector
grad(1:nx,1:nx) = - eye(nx); %%%%% not sure here of the sign (should work both ways)
for ii = 1:N
    grad((1 + nx +(ii - 1)*nx):((nx + ii*nx)),(1 +(ii - 1)*(nx+nu)):((ii - 1)*(nx+nu) + nx)) = ...
         eye(nx) + h*fx(x(:,ii),u(:,ii));
    grad((1 + nx +(ii - 1)*nx):((nx + ii*nx)),(1 +(ii)*(nx+nu)):((ii)*(nx+nu) + nx)) = ...
         - eye(nx);
    grad((1 + nx +(ii - 1)*nx):((nx + ii*nx)),(1 +(ii - 1)*(nx+nu) + nx):((ii - 1)*(nx+nu) + nx + nu)) = ...
         + h*fu(x(:,ii),u(:,ii));
end
grad = grad.';
end

end