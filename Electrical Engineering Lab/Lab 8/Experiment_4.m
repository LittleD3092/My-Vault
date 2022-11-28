sys = tf([0.1, 1], [0.002, 0.11, 1])
stepinfo(sys)

% find delayTime
[y, t] = step(sys, 0.5);
differenceValues = abs(y - y(end)/2);
[~, index] = min(differenceValues);
delayTime = t(index)

[y, t] = step(sys, 0.5);
sserror=abs(1-y(end))

step(sys, 0.5)
grid on