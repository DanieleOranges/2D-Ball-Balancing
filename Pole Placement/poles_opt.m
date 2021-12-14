clear
clc
close all
%% Optimization

gitdir = 'C:\Users\ricci\Desktop\Progetto Meccatronica\2D-Ball-Balancing\';
lb = [10  5   1  0.1];
ub = [35  20  10  8 ]; 
nvar = 4; 
% options = optimoptions('surrogateopt');
% options.UseParallel = true; 
warning off 
options_ga = optimoptions('gamultiobj');           % Nome dell'algoritmo, creo le opzioni

options_ga.UseParallel         =  true;                                % Attivo il parallel computing (si risolve in molto meno tempo)
options_ga.UseVectorized       =  false;                               % Non lo so
options_ga.Display             =  'iter';                              % Mostra ogni generazione i risultati
options_ga.PlotFcn             =   {@gaplotpareto, @gaplotstopping};     % Plotta best e mean fitness in ogni generazione
options_ga.MaxGenerations      =   200;                             % Numero massimo di generazioni, di solito si ferma a 5000
% options_ga.FunctionTolerance   =   1e-11;                            % Tolleranza di convergenza sulla fitness
options_ga.PopulationSize      =   30;                             % Size della popolazione iniziale
% options_ga.MaxStallGenerations =   50;                               % Generazioni di stallo        

% x = particleswarm(@(x) opt_pp_fcn(x, gitdir),nvars,lb,ub,options);
% [x,fval,exitflag,output] = surrogateopt(@(x) opt_pp_fcn(x, gitdir), lb, ub, [], options)
           % p1 p2 p3 p4
lin_coeff = [0 0 -1 1;...
             0 -1 1 0 ; ...
             -1 1 0 0 ; ...
             0 0 0 0];

t_noti = [0 0 0 0]'; 

lin_coeff_eq = []; 
t_noti_eq = []; 

[x,fval,exitflag,output] = gamultiobj(@(x) opt_pp_fcn(x, gitdir), nvar, lin_coeff, t_noti, lin_coeff_eq, t_noti_eq, lb, ub, [], [], options_ga)  

%% PLOT

    refx = 0.05; 
    refy = 0.05; 
    
    %%
    idx = size(x);
    for ii = 1:idx(1)

    poles = x(ii, :);
    PP_sim = pole_placement(-poles, -poles);
% 

    cd([gitdir, 'Simulation\'])
    sim_data
    options = simset('SrcWorkspace','current');

    out = sim('nl_model.slx', [],options);

    cd([gitdir, 'Pole Placement\'])
%    res = mean(max(out.x) r- xref, max(out.y) - yref)
% 
    figure(ii)

    
    subplot(2, 1, 1)
    plot(out.x)
    title(num2str(-poles))
    subplot(2, 1, 2)
    plot(out.y)
%     title(num2str(fval(ii, :)))
    end

    %%
    opt_pp_fcn(x, gitdir)
%%


%% Functions
function [res] = opt_pp_fcn(x, gitdir)
warning off 

    poles = x; 
    refx = 0.05; 
    refy = 0.05;
    
try

    PP_sim = pole_placement(-poles, -poles);
    
    cd([gitdir, 'Simulation\'])
    sim_data
    options = simset('SrcWorkspace','current');

    out = sim('nl_model.slx', [],options);

    tr_x = out.x.Time(out.x.Data>=refx);
    tr_y = out.y.Time(out.y.Data>=refy);

    cd([gitdir, 'Pole Placement\'])
   
    res(1)  = mean([tr_x(1), tr_y(1)]); 
    res(2)  = mean([max(out.x.Data)-refx, max(out.y.Data)-refy]);

catch
    res = [5, 0.2];
end


end
