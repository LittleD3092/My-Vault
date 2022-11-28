sys = tf(1, [0.002, 0.01, 1])
stepinfo(sys)
step(sys, 2)
grid on