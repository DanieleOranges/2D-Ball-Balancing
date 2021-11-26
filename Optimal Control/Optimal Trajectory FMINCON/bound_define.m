function [lb,ub] = bound_define(xref,max_errx,max_errv,max_u,nx,nu,N)

lb = zeros(N*(nx + nu) + nx,1);
ub = zeros(N*(nx + nu) + nx,1);

lb(1:nx,1) = -1e3; lb(nx:nx+nu) = -1e3;
ub(1:nx,1) = +1e3; ub(nx:nx+nu) = +1e3;

% Construction of array size N
for ii = 1:N
    idx = (1 + ii*(nu + nx)):(nx + ii*(nu + nx));
    % Velocity constraints
    lb(idx([1,3])) = - max_errv;
    ub(idx([1,3])) = + max_errv;  
    % Position constraints
    lb(idx([2,4])) = xref([2,4],ii+1) - max_errx;
    ub(idx([2,4])) = xref([2,4],ii+1) + max_errx;    
end    
for ii = 1:N-1
    lb((1 + nx + ii*(nu + nx)):(nx + nu + ii*(nu + nx))) = - max_u;
    ub((1 + nx + ii*(nu + nx)):(nx + nu + ii*(nu + nx))) = + max_u;
end