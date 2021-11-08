lambdap = adjoint_vect(t,time,lambda,u,x,xref,obj)


% ~~~~~~~~~~~~~~~~~~ Parameter extraction from obj ~~~~~~~~~~~~~~~~~~~~~~ %
Lx = obj.Lx; Lu = obj.Lu;
Cx = obj.Cx; Cu = obj.Cu;
A  =  obj.A;  B =  obj.B;
lambdap = zeros(4,1);

% ~~~~~~~~~~~~~~~~~~~~~ Adjoint vector dynamics ~~~~~~~~~~~~~~~~~~~~~~~~~ %
lambdap = -A'*lambda - Lx' - Cx'*inv(Cu*Cu')*Cu*(-Lu -B'*lambda);
