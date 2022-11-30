## 5-11

```matlab
a = [1 4 16 36];
b = [0.6 2 5.6 9.6];
t = 0:0.1:8;
y = zeros(81, 4);
for i = 1:4;
    num = [a(i)];
    den = [1 b(i) a(i)];
    y(:, i) = step(num, den, t);
end
plot(t, y(:, 1), 'o', t, y(:, 2), 'x', t, y(:, 3), '-', t, y(:, 4), '-.')
grid
title('Unit-Step Response Curves for Four Cases')
xlabel('t Sec')
ylabel('Outputs')
gtext('1')
gtext('2')
gtext('3')
gtext('4')
```

![[hw5_11.png]]

## 5-15

### Method 1

```matlab
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
```

![[hw5_15_method1_pic1.png]]
![[hw5_15_method1_pic2.png]]
![[hw5_15_method1_pic3.png]]

### Method 2

- For different $\zeta$, the number of computation points are different.
- For different initial value `x0`, the output waveform is different.

File `main.m`:

```matlab
clear;
clf;
format short e
options = [];

y = zeros(77, 6);
for i = 1:6
    m = 2*(i-1)*0.2;
    n = 1;
    x0 = [5 1]; % dunno what this is yet
    [t, x] = ode45('par_pass', [0 12], x0, options, m, n);
    plot(t, (n) * x(:, 2) + (m) * x(:, 1) + 1)
    y(1:length(t), i) = (n) * x(:, 2) + (m) * x(:, 1) + 1;
    hold on
end
hold off

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
```

File `par_pass.m`:

```matlab
function q = par_pass(t, p, flag, m, n)
    x1 = p(1); x2 = p(2);

    u = 1;

    q = zeros(2, 1);
    q(1) = x2;
    q(2) = -n*x1-m*x2 + u;
```

![[pic1.png]]

![[pic2.png]]

![[pic3.png]]