function [OutVect] = DRE(t,p,Q,R,X,Tx,c,Tc)

% evaluation of the state at time @t
Nstates = size(X,2);
xk = zeros(1,Nstates);
for ii = 1:Nstates
    xk(:,ii) = interp1(Tx,X(:,ii),t);
end

% evaluation of the control action at time @t
Nc = size(c,2);
ck = zeros(1,Nc);
for ii = 1:Nc
    ck(:,ii) = interp1(Tc,c(:,ii),t);
end

A = fx(xk);
B = fc();

% transformation vector -> matrix
P = zeros(Nstates,Nstates);
P(1:end) = p(1:end);

% DRE
Out = -(A.'*P + P*A - P*B*R^-1*B.'*P + Q);

% transformation matrix -> vector
OutVect = Out(1:end)';