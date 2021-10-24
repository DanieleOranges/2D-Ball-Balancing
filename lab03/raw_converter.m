clear
clc
close all
set(0, 'DefaultFigureWindowStyle', 'docked')

txt2mat_lab2; 
callback;

for ii=1:length(test_raw)
    test(ii).laser = test_raw(ii).laser;
    test(ii).mot   = polyval(Pt1, test_raw(ii).mot);

    test(ii).t = test_raw(ii).t;
    test(ii).name = test_raw(ii).name;


%     
end

save('lab2', 'test')
%%
figure

subplot(2,2,1)
plot(test(3).t(1:end-1), diff(test(3).mot)./diff(test(3).t)) 

subplot(2,2,3)
plot(test(3).t, test(3).laser) 


subplot(2,2,2)
plot(test(2).t(1:end-1), diff(test(2).mot)./diff(test(2).t)) 

subplot(2,2,4)
plot(test(2).t, test(2).laser) 

