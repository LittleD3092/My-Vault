#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Sample code of HW3 Problem 5
Monte Carlo estimate of the Euler Number
"""
import numpy as np
from scipy import stats
import matplotlib.pyplot as plt
from tqdm import tqdm

def run_monte_carlo(N_trials = 1000):
    # Basic parameters
    n_list = []

    #-------- Your code (~10 lines) ----------
    for _ in tqdm(range(N_trials)):
        S = 0
        n = 0
        while S <= 1:
            U_i = np.random.uniform(0, 1)
            S += U_i
            n += 1
        n_list.append(n)
    euler_number_est = np.mean(n_list)

    #---------- End of your code -----------
    # Optional: Print the Monte-Carlo estimates abnd visualize the empirical CDF
    print(euler_number_est)
    # print(n_list)
    res = stats.ecdf(np.array(n_list))
    ax = plt.subplot()
    res.cdf.plot(ax)
    ax.set_xlabel('Estimated Euler Number')
    ax.set_ylabel('Empirical CDF')
    plt.savefig(f'hw3_problem5_mc_{N_trials}.png')
    # close the plot
    plt.close()

if __name__ == '__main__':
    N_trials_list = [10,1000,100000,10000000]
    for N_trials in N_trials_list:
        run_monte_carlo(N_trials)