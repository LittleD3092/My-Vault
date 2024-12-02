# Problem 6

## a. Mean regrets

Total regrets of my **Epsilon-Greedy algorithm**:

| Epsilon $\epsilon$ | Problem 1 | Problem 2 | Problem 3 | Mean Regret |
| ------------------ | --------- | --------- | --------- | ----------- |
| 0.01               | 491.88    | 306.96    | 441.99    | 413.61      |
| 0.03               | 296.85    | 221.91    | 254.57    | 257.78      |
| 0.1                | 459.07    | 392.92    | 152.64    | 334.88      |
| 0.3                | 1219.6    | 1032.1    | 229.97    | 827.22      |
Last regrets of my **Epsilon-Greedy algorithm**:

| Epsilon $\epsilon$ | Problem 1 | Problem 2 | Problem 3 | Mean Regret |
| ------------------ | --------- | --------- | --------- | ----------- |
| 0.01               | 491.55    | 306.79    | 441.52    | 413.29      |
| 0.03               | 296.48    | 221.6     | 254.35    | 257.48      |
| 0.1                | 458.07    | 391.98    | 152.45    | 334.17      |
| 0.3                | 1216.7    | 1029.7    | 229.45    | 825.28      |
Total regrets of **Empirical Means algorithm**:

| Epsilon $\epsilon$ | Problem 1 | Problem 2 | Problem 3 | Mean Regret |
| ------------------ | --------- | --------- | --------- | ----------- |
| 0.01               | 408.56    | 104.1     | 422.72    | 311.79      |
| 0.03               | 357.9     | 52.691    | 400.93    | 270.51      |
| 0.1                | 538.85    | 42.972    | 407.95    | 329.92      |
| 0.3                | 359.08    | 92.916    | 469.65    | 307.22      |

Last regrets of **Empirical Means algorithm**:

| Epsilon $\epsilon$ | Problem 1 | Problem 2 | Problem 3 | Mean Regret |
| ------------------ | --------- | --------- | --------- | ----------- |
| 0.01               | 407.58    | 103.86    | 421.69    | 311.04      |
| 0.03               | 357.04    | 52.574    | 399.95    | 269.85      |
| 0.1                | 537.56    | 42.879    | 406.95    | 329.13      |
| 0.3                | 358.22    | 92.699    | 468.5     | 306.47      |

- Comparing the results, we can see that both algorithms perform the best when $\epsilon=0.03$. Larger or smaller $\epsilon$ leads to higher regrets.
- Overall, Empirical Means algorithm is better since it has lower regrets in $\epsilon = 0.01, 0.1, \text{or }0.3$. When $\epsilon=0.03$, Epsilon-Greedy algorithm performs only slightly better.
- Empirical Means algorithm is less sensitive to the variations in $\epsilon$ compared to Epsilon-Greedy algorithm.

In conclusion, Epsilon-Greedy algorithm can perform better but requires tuning $\epsilon$.

## b. Diminishing exploration rate

| Alpha $\alpha$ | Problem 1 Last Regrets | Problem 1 Total Regrets | Problem 2 Last Regrets | Problem 2 Total Regrets | Problem 3 Last Regrets | Problem 3 Total Regrets | Mean Regret |
| -------------- | ---------------------- | ----------------------- | ---------------------- | ----------------------- | ---------------------- | ----------------------- | ----------- |
| 0.1            | 1773                   | 1776.8                  | 1498.7                 | 1502                    | 308.64                 | 309.32                  | 1196.04     |
| 0.5            | 135.17                 | 135.3                   | 107.04                 | 107.22                  | 225.79                 | 226.1                   | 156.21      |
| 1.0            | 869.51                 | 871.4                   | 587.58                 | 588.81                  | 759.52                 | 761.33                  | 740.51      |
| 2.0            | 2834.2                 | 2841.2                  | 3111.7                 | 3119.4                  | 864.82                 | 866.95                  | 2275.85     |

- When $\alpha$ is low, the mean regret is higher because more exploration will be carried.
- When $\alpha$ is optimal, the mean regret is lower because the exploration and exploitation phase are balanced.
- When $\alpha$ is high, the mean regret is also higher because more exploration will occur.

In conclusion, setting the optimal $\alpha$ will balance the exploration and exploitation, which result in lower regrets. In this experiment, $\alpha = 0.5$ yields the best result.