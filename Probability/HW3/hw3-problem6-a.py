import matplotlib.pyplot as plt

# Data for total regrets
total_regrets_eps_greedy = {
    "Epsilon": [0.01, 0.03, 0.1, 0.3],
    "Problem 1": [491.88, 296.85, 459.07, 1219.6],
    "Problem 2": [306.96, 221.91, 392.92, 1032.1],
    "Problem 3": [441.99, 254.57, 152.64, 229.97],
    "Mean Regret": [413.61, 257.78, 334.88, 827.22],
}

total_regrets_empirical_means = {
    "Epsilon": [0.01, 0.03, 0.1, 0.3],
    "Problem 1": [408.56, 357.9, 538.85, 359.08],
    "Problem 2": [104.1, 52.691, 42.972, 92.916],
    "Problem 3": [422.72, 400.93, 407.95, 469.65],
    "Mean Regret": [311.79, 270.51, 329.92, 307.22],
}

# Data for last regrets
last_regrets_eps_greedy = {
    "Epsilon": [0.01, 0.03, 0.1, 0.3],
    "Problem 1": [491.55, 296.48, 458.07, 1216.7],
    "Problem 2": [306.79, 221.6, 391.98, 1029.7],
    "Problem 3": [441.52, 254.35, 152.45, 229.45],
    "Mean Regret": [413.29, 257.48, 334.17, 825.28],
}

last_regrets_empirical_means = {
    "Epsilon": [0.01, 0.03, 0.1, 0.3],
    "Problem 1": [407.58, 357.04, 537.56, 358.22],
    "Problem 2": [103.86, 52.574, 42.879, 92.699],
    "Problem 3": [421.69, 399.95, 406.95, 468.5],
    "Mean Regret": [311.04, 269.85, 329.13, 306.47],
}

x = total_regrets_eps_greedy["Epsilon"]
y1 = total_regrets_eps_greedy["Mean Regret"]
y2 = total_regrets_empirical_means["Mean Regret"]
y3 = last_regrets_eps_greedy["Mean Regret"]
y4 = last_regrets_empirical_means["Mean Regret"]

plt.plot(x, y1, label="Total Regrets (Epsilon-Greedy)")
plt.plot(x, y2, label="Total Regrets (Empirical Means)")
plt.plot(x, y3, label="Last Regrets (Epsilon-Greedy)")
plt.plot(x, y4, label="Last Regrets (Empirical Means)")

plt.xlabel("Epsilon")
plt.ylabel("Mean Regret")
plt.title("Mean Regret vs Epsilon")

plt.legend()
plt.savefig("hw3-problem6-a.png")