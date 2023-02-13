sys = tf(1, [0.002, 0.01, 1])
stepinfo(sys)

% find delayTime
[y, t] = step(sys, 2);
differenceValues = abs(y - y(end)/2);
[~, index] = min(differenceValues);
delayTime = t(index)

[y, t] = step(sys, 2);
sserror=abs(1-y(end))

step(sys, 2)
grid on