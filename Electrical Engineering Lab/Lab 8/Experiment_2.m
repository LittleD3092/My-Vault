sys = tf(10, [0.2, 11])
stepinfo(sys)

[y, t] = step(sys, 0.5);
sserror=abs(1-y(end))

step(sys, 0.5)
grid on