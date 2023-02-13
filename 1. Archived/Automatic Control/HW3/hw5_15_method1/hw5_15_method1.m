t = 0:0.2:12;
for n = 1:6
    num = [1];
    den = [1 2*(n-1)*0.2 1];
    [y(1:61, n), x, t] = step(num, den, t);
end
plot(t, y)
grid
title('Unit-Step Response Curves')
xlabel('t Sec')
ylabel('Outputs')
gtext('\zeta = 0')
gtext('0.2')
gtext('0.4')
gtext('0.6')
gtext('0.8')
gtext('1.0')

pause

mesh(y)
title('Three-Dimensional Plot of Unit-Step Response Curves using Command "mesh(y)"')
xlabel('n, where n = 1, 2, 3, 4, 5, 6')
ylabel('Computation Time Points')
zlabel('Outputs')

pause

mesh(y')
title('Three-Dimensional Plot of Unit-Step Response Curves using Command "mesh(y transpose)"')
xlabel('Computation Time Points')
ylabel('n, where n = 1, 2, 3, 4, 5, 6')
zlabel('Outputs')