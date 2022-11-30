clear;
clf;
format short e
options = [];

y = zeros(61, 6);
for i = 1:6
    m = 2*(i-1)*0.2;
    n = 1;
    x0 = [0 0]; % dunno what this is yet
    [t, x] = ode45('par_pass', [0 12], x0, options, m, n);
    plot(t, x)
    pause
end
pause
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