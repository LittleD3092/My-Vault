% file name t1.m
clear;
clf;
format short e
x0=[5 1];
options = [];
m=5;
n=20;
[t,x]=ode45('par_pass',[0 10],x0,options,m,n);
plot(t,x)