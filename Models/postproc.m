data

sim('multibody_sys.slx')
multi = ans;
sim('linear_sys.slx')
lin = ans; 
sim('non_linear_sys.slx')
nl = ans; 

figure
subplot(2,1,1)
hold on 
plot(multi.x)
plot(lin.x)
plot(nl.x)
ylabel('X [m]')
xlabel('T [s]')
legend('Multibody', 'Linear', 'Non-Linear')

subplot(2,1,2)
hold on 
plot(multi.y)
plot(lin.y)
plot(nl.y)
ylabel('Y [m]')
xlabel('T [s]')
legend('Multibody', 'Linear', 'Non-Linear')

