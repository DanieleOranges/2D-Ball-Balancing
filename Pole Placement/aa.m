close all

figure
plot(x, y, '--k', 'LineWidth', 1.2)
xlabel('X')
ylabel('Y')
hold on
for ii = 1:length(out.x.Data)/500
plot(out.x.Data(1+ (ii-1)*500), out.y.Data(1+ (ii-1)*500), 'ro', 'LineWidth', 1.8)
saveas(gcf, ['img/', num2str(ii), '.png'])
end