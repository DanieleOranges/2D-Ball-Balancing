function stop = outfun(x,optimValues,state,param)

stop = 0;
switch state
    case 'iter'
          subplot(2,2,1); plot(optimValues.iteration+1,x(end),'*b')
          subplot(2,2,2); plot(optimValues.iteration+1,optimValues.fval,'*b')
          subplot(2,2,3); plot(optimValues.iteration+1,optimValues.constrviolation,'*b')
          subplot(2,2,4); plot(optimValues.iteration+1,optimValues.firstorderopt,'*b')  
          pause(0.1)
    case 'interrupt'
    case 'init'
          subplot(2,2,1); hold on; grid on; title('$Time$','Interpreter','latex')
          subplot(2,2,2); hold on; grid on; title('$Cost functional$','Interpreter','latex')
          subplot(2,2,3); hold on; grid on; title('$Constraint Violation$','Interpreter','latex')
          subplot(2,2,4); hold on; grid on; title('$1 Order optimality$','Interpreter','latex') 
          pause(1)
    case 'done'
otherwise
end