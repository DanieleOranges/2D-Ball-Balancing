function [OutVect] = DRE(t,p,Q,R,x,c,T)

% evaluation of the state at time @t
Nstates = size(x,2);
xk = zeros(1,Nstates);
for ii = 1:Nstates
    xk(:,ii) = interp1(T,x(:,ii),t);
end

% evaluation of the control action at time @t
Nu = size(c,2);
uk = zeros(1,Nu);
for ii = 1:Nu
    uk(:,ii) = interp1(T,c(:,ii),t);
end

A = fx(xk);
B = fu(uk);

% transformation vector -> matrix
P = zeros(Nstates,Nstates);
P(1:end) = p(1:end);

% DRE
Out = -(A.'*P + P*A - P*B*pinv(R)*B.'*P + Q);

% transformation matrix -> vector
OutVect = Out(1:end)';