data

sim('multibody_2d_ball.slx')
multi = ans;
sim('mechanical_system.slx')
lin = ans; 
sim('pid_non_lineare.slx')
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

