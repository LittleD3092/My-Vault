# Probability HW2 Problem 5 Report

## 1. The accuracy of the classifier with a 70/30% partition of the dataset and a uniform prior

The accuracy is 0.9796650717703349.

## 2. Using different prior distributions and partition

| ![[Pasted image 20241019145632.png]] | ![[Pasted image 20241019150945.png]] |
| ------------------------------------ | ------------------------------------ |

As the prior increases from 0.1 to 0.5, the accuracy improves. However, when beyond 0.5, the improvements become less significant, which indicates that the model benefits from assuming a higher proportion of "ham" in the dataset.

Near 0.1, the accuracy is lower because the training set is too small. Near 0.9, the accuracy is better because more training helps. In the middle, the accuracy peaks at 0.5 and decreases slightly probably because the model overfit without enough data for a comprehensive training.