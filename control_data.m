%% Data of all the good Controllers


%% Pole Placement

addpath('Pole Placement')
pfast = [-25, -20, -4, -1.5]
pslow = [-20, -15, -4, -0.8];
fast = pole_placement(pfast, pfast);
slow = pole_placement(pslow, pslow);
% 
rmpath('Pole Placement')


%% LQR

h = 0.1;

addpath('Optimal Control\LQR')

barc.open.opt = load('Optimal Control\OptimalResults\Optimal_Open_Lap_Barcelona.mat');
barc.open.lqr = LQR_matrix(barc.open.opt, h);

barc.closed.opt = load('Optimal Control\OptimalResults\Optimal_Other_Lap_Barcelona.mat');
barc.closed.lqr = LQR_matrix(barc.closed.opt, h);

monza.open.opt = load('Optimal Control\OptimalResults\Optimal_Monza.mat');
monza.open.lqr = LQR_matrix(monza.open.opt, h);

monza.closed.opt = load('Optimal Control\OptimalResults\Optimal_Monza.mat');
monza.closed.lqr = LQR_matrix(monza.closed.opt, h);


monte.open.opt = load('Optimal Control\OptimalResults\Optimal_MonteCarlo.mat');
monte.open.lqr = LQR_matrix(monte.open.opt, h);

monte.closed.opt = load('Optimal Control\OptimalResults\Optimal_MonteCarlo.mat');
monte.closed.lqr = LQR_matrix(monte.closed.opt, h);

rmpath('Optimal Control\LQR')


