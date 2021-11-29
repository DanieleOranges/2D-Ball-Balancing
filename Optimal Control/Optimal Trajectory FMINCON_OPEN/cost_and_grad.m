function [cost,grad] = cost_and_grad(z,param)

N = param.N;
nx = param.nx;
nu = param.nu;
h = param.h;

L = param.L;
p = param.p;
xref = param.xref;

% extract states and control from z
x = zeros(nx,N+1); u = zeros(nu,N);
for ii = 0:N
    x(:,ii+1) = z((1 + ii*(nu + nx)):(nx + ii*(nu + nx)));
end    
for ii = 0:N-1
    u(:,ii+1) = z((1 + nx + ii*(nu + nx)):(nx + nu + ii*(nu + nx)));    
end
    
% Cost Function 
cost = 0;
for ii = 1:N
    cost = cost + z(end).*L(x(:,ii),u(:,ii),xref(:,ii),h);
end
cost = cost + p(x(:,end));

if nargout > 1
% Gradient of the objective function
Lx = param.Lx;
Lu = param.Lu;
px = param.px;

grad = zeros(size(z));
for ii = 0:N-1
    grad((1 + ii*(nu + nx)):(nx + ii*(nu + nx)),1) = h*Lx(x(:,ii + 1),u(:,ii + 1));    
    grad((1 + nx + ii*(nu + nx)):(nx + nu + ii*(nu + nx)),1) = h*Lu(x(:,ii + 1),u(:,ii + 1));    
end
grad(end - nx + 1:end,1) = px(x(:,end));
end

end