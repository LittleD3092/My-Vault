#automatic-control 

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
clear ;
t=0:0.2:12;
%let y1,y2 be the output
y1=zeros(61,6);
y2=zeros(61,6);
options=[];
for i=1:6
 %using transfer function
 num=[1];
 den=[1 2*(i-1)*0.2 1];
 %use step response simulation function
 [y1(1:61,i)] = step(num,den,t);

 %using ODE45
%transfer function to state-space representation
[a,b,c,d]=tf2ss(num,den);
%use ODE45 to solve the state-space function soultion x1
and x2
 [t2,tmp]= ode45('par_pass',t,[0 0],options,a,b);
%t2: time (sec), tmp: array of x’s derivative and y

 % in par_pass.m q(2) is output value (y)
 y2(:,i)=tmp(:,2);
end
%plot the figure of different damping ratio in 2D and 3D using
both matlab built-in function and ODE45 (for 3D plot use
mesh(y))
% for subplot number 1,3,5 : solve with built-in function
% for subplot number 2,4,6 : solve with ODE45
subplot(3,2,1);
plot(t,y1)
grid on
title('Two Dimensional Plot')
xlabel('t (sec)')
ylabel('outputs')
gtext('\rho = 0','FontSize',8)
gtext('0.2','FontSize',8)
gtext('0.4','FontSize',8)
gtext('0.6','FontSize',8)
gtext('0.8','FontSize',8)
gtext('1.0','FontSize',8)
subplot(3,2,3);
mesh(y1)
title('Three Dimensional Plot -1')
xlabel('n, where n = 1,2,3,4,5,6')
ylabel('Computation Time Points')
zlabel('Outputs')
subplot(3,2,5);
mesh(y1')
title('Three Dimensional Plot -2')
ylabel('n, where n = 1,2,3,4,5,6')
xlabel('Computation Time Points')
zlabel('Outputs')
subplot(3,2,2);
plot(t2,y2)
grid on
title('ODE45 Two Dimensional Plot -1')
xlabel('t (sec)')
ylabel('outputs')
gtext('\rho = 0','FontSize',8)
gtext('0.2','FontSize',8)
gtext('0.4','FontSize',8)
gtext('0.6','FontSize',8)
gtext('0.8','FontSize',8)
gtext('1.0','FontSize',8)
subplot(3,2,4);
mesh(y2)
title('ODE45 Three Dimensional Plot -1')
xlabel('n, where n = 1,2,3,4,5,6')
ylabel('Computation Time Points')
zlabel('Outputs')
subplot(3,2,6);
mesh(y2')
title('ODE45 Three Dimensional Plot -2')
ylabel('n, where n = 1,2,3,4,5,6')
xlabel('Computation Time Points')
zlabel('Outputs')
sgtitle('A-5-11 Graph')
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