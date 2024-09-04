# 1. Ship Titanic

## 1.1. Are there age differences between cabin classes? Which group is different from the others?

Because there are three or more independent groups, we will use ANOVA test to determine whether there is a significant difference between the means of the groups. We will use the following hypotheses:

- **Null Hypothesis:** The mean ages of passengers in the first-class, second-class, and third-class cabins are equal.
- **Alternative Hypothesis:** The mean ages of passengers in the first-class, second-class, and third-class cabins are not equal.

We will use a significance level of 0.05. If the p-value is less than 0.05, we will reject the null hypothesis. To calculate the p-value and the test statistic, the following python code will be used:

```python
# read data
file_path = '../data/q1/Titanic_R.csv'
titanic_data = pd.read_csv(file_path)

# remove trailing whitespace
titanic_data.columns = titanic_data.columns.str.strip()
titanic_data = titanic_data.apply(lambda x: x.str.strip() if x.dtype == "object" else x)
# drop missing values
titanic_data.replace('', np.nan, inplace=True)
titanic_data.dropna(subset=['age', 'pclass'], inplace=True)
# convert age to float
titanic_data['age'] = titanic_data['age'].astype(float)

# get age data for each class
first_class_ages = titanic_data[titanic_data['pclass'] == 1]['age']
second_class_ages = titanic_data[titanic_data['pclass'] == 2]['age']
third_class_ages = titanic_data[titanic_data['pclass'] == 3]['age']

# perform ANOVA
f_stat, p_value = stats.f_oneway(first_class_ages, second_class_ages, third_class_ages)

# print results
print('F-statistic:', f_stat)
print('P-value:', p_value)

# accept or reject null hypothesis
if p_value < 0.05:
    print('There is a significant difference in the mean ages of passengers in different classes. Reject null hypothesis.\n')
else:
    print('There is no significant difference in the mean ages of passengers in different classes. Accept null hypothesis.\n')
```

The results of the ANOVA test are printed to the console, as shown below:

```
F-statistic: 108.32597769816022
P-value: 1.7972028849109706e-43
There is a significant difference in the mean ages of passengers in different classes. Reject null hypothesis.
```

Since the p-value is less than 0.05, we reject the null hypothesis. Now, we know that there is a significant difference in the mean ages of passengers in different classes. To determine which group is different from the others, we can perform post-hoc tests such as Tukey's HSD test. The following python code will be used to perform the Tukey's HSD test:

```python
# tukey test
tukey = pairwise_tukeyhsd(titanic_data['age'], titanic_data['pclass'], alpha=0.05)
print(tukey)
tukey.plot_simultaneous()
plt.title("Tukey HSD Test for Age Differences between Passenger Classes")
plt.xlabel("Age")
plt.ylabel("Passenger Class")
plt.savefig("../pics/q1_tukey.png")
```

The results of the Tukey's HSD test are printed to the console, as shown below:

```
 Multiple Comparison of Means - Tukey HSD, FWER=0.05 
=====================================================
group1 group2 meandiff p-adj  lower    upper   reject
-----------------------------------------------------
     1      2  -9.6532   0.0 -12.2953  -7.0111   True
     1      3 -14.3436   0.0 -16.6322 -12.0549   True
     2      3  -4.6903   0.0  -7.0425  -2.3382   True
-----------------------------------------------------
```

And the plot of the Tukey's HSD test is shown as follows:

![q1_tukey](q1_tukey.png)

We can see from the plot that the confidence intervals for all three classes do not overlap, indicating that there is a significant difference in the mean ages of passengers in different classes.

From the plot and the results of the Tukey's HSD test, we can conclude that the mean ages of passengers in the first-class, second-class, and third-class cabins are significantly different from each other.

## 1.2. Among these passengers, are the survival status/proportions  (column name: survived) different among passengers in different levels of cabins (column name: pclass)? 

Because both `pclass` and `survived` are categorical variables, we can use the chi-square test to determine whether there is a significant association between the two variables. We will use the following hypotheses:

- **Null Hypothesis:** There is no association between the passenger class and the survival status.
- **Alternative Hypothesis:** There is an association between the passenger class and the survival status.

We will use a significance level of 0.05. If the p-value is less than 0.05, we can reject the null hypothesis and know that there is an association between the two variables. To calculate the p-value and the test statistic, the following python code will be used:

```python
contingency_table = pd.crosstab(titanic_data['pclass'], titanic_data['survived'])
chi2, p, dof, expected = stats.chi2_contingency(contingency_table)
print('Chi-square statistic:', chi2)
print('P-value:', p)
if p < 0.05:
    print('There is a significant association between passenger class and survival. Reject null hypothesis.\n')
else:
    print('There is no significant association between passenger class and survival. Accept null hypothesis.\n')
print("Contingency Table:")
print(contingency_table)
```

The results of the chi-square test are printed to the console, as shown below:

```
Chi-square statistic: 107.49758081619217
P-value: 4.541474884670159e-24
There is a significant association between passenger class and survival. Reject null hypothesis.

Contingency Table:
survived    0    1
pclass
1         103  181
2         146  115
3         370  131
```

From the results, we can see that the p-value is extremely small and much lower than the common significance level of 0.05. Therefore, we reject the null hypothesis and conclude that there is a significant association between passenger class and survival status.

From the contingency table, we can know that First-class passengers had a much higher survival rate compared to second and third-class passengers. The survival rate of third-class passengers was the lowest among the three classes.

# 2. COVID-19 Dataset

## 2.1. Is the Fatality Ratio (column name: Case_Fatality_Ratio) on 2022/07/07 (file name 07-07-2022) lower than the Fatality Ratio on 2021/07/07? (file name 07-07-2021)

Since the fatality ratio values are indexed by regions `Combined_Key`, we can use a paired t-test to compare the fatality ratios between the two dates. We will use the following hypotheses:

- **Null Hypothesis:** The fatality ratio on 2022/07/07 is not lower than the fatality ratio on 2021/07/07.
- **Alternative Hypothesis:** The fatality ratio on 2022/07/07 is lower than the fatality ratio on 2021/07/07.

We will use a significance level of 0.05. If the p-value is less than 0.05, we can reject the null hypothesis and conclude that the fatality ratio on 2022/07/07 is lower than the fatality ratio on 2021/07/07. To calculate the p-value and the test statistic, the following python code will be used:

```python
import pandas as pd
import numpy as np
import scipy.stats as stats

file_2021 = '../data/q2/07-07-2021.csv'
file_2022 = '../data/q2/07-07-2022.csv'

data_2021 = pd.read_csv(file_2021)
data_2022 = pd.read_csv(file_2022)

# remove trailing whitespace
data_2021.columns = data_2021.columns.str.strip()
data_2021 = data_2021.apply(lambda x: x.str.strip() if x.dtype == "object" else x)
data_2022.columns = data_2022.columns.str.strip()
data_2022 = data_2022.apply(lambda x: x.str.strip() if x.dtype == "object" else x)

# merge data
merged_data = pd.merge(data_2021, data_2022, on='Combined_Key', suffixes=('_2021', '_2022'))

# drop missing values
merged_data.replace('', np.nan, inplace=True)
merged_data.dropna(subset=['Case_Fatality_Ratio_2021', 'Case_Fatality_Ratio_2022'], inplace=True)

# convert fatality ratio to float
merged_data['Case_Fatality_Ratio_2021'] = merged_data['Case_Fatality_Ratio_2021'].astype(float)
merged_data['Case_Fatality_Ratio_2022'] = merged_data['Case_Fatality_Ratio_2022'].astype(float)

# extract case fatality ratio data and perform one-sided paried t-test
fatality_ratio_2021 = merged_data['Case_Fatality_Ratio_2021']
fatality_ratio_2022 = merged_data['Case_Fatality_Ratio_2022']
t_stat, p_value = stats.ttest_rel(fatality_ratio_2021, fatality_ratio_2022, alternative='greater')

# print results
print('T-statistic:', t_stat)
print('P-value:', p_value)
if p_value < 0.05:
    print('The fatality ratio on 07-07-2022 is significantly lower than the fatality ratio on 07-07-2021. Reject null hypothesis.')
else:
    print('The fatality ratio on 07-07-2022 is not significantly lower than the fatality ratio on 07-07-2021. Accept null hypothesis.')
```

The results of the paired t-test are printed to the console, as shown below:

```
T-statistic: 2.5612427618959197
P-value: 0.005233258075386552
The fatality ratio on 07-07-2022 is significantly lower than the fatality ratio on 07-07-2021. Reject null hypothesis.
```

Since the p-value is less than 0.05, we reject the null hypothesis and conclude that the fatality ratio on 2022/07/07 is significantly lower than the fatality ratio on 2021/07/07.

# 3. Customer Dataset

## 3.1. Is the customer rating (column name: Customer_rating) associated with if the products reached on time (Reached.on.Time_Y.N)?

Since `Customer_rating` and `Reached.on.Time_Y.N` are considered categorical variables, we can use the chi-square test to determine if there is an association between the two variables. We will use the following hypotheses:

- **Null Hypothesis:** There is no association between customer rating and whether the products reached on time.
- **Alternative Hypothesis:** There is an association between customer rating and whether the products reached on time.

We will use a significance level of 0.05. If the p-value is less than 0.05, we can reject the null hypothesis and conclude that there is an association between the two variables. To calculate the p-value and the test statistic, the following python code will be used:

```python
import pandas as pd
from scipy import stats
import numpy as np

file_path = '../data/q3/Train.csv'
data = pd.read_csv(file_path)

# remove trailing whitespace
data.columns = data.columns.str.strip()
data = data.apply(lambda x: x.str.strip() if x.dtype == "object" else x)

# drop missing values
data.replace('', np.nan, inplace=True)
data.dropna(subset=['Customer_rating', 'Reached.on.Time_Y.N'], inplace=True)

# create contingency table
contingency_table = pd.crosstab(data['Customer_rating'], data['Reached.on.Time_Y.N'])

# perform chi-square test
chi2, p, _, _ = stats.chi2_contingency(contingency_table)

# print results
print('Chi-square statistic:', chi2)
print('P-value:', p)

if p < 0.05:
    print('There is a significant association between customer rating and on-time delivery. Reject null hypothesis.')
else:
    print('There is no significant association between customer rating and on-time delivery. Accept null hypothesis.')

print('Contingency table:')
print(contingency_table)
```

The results of the chi-square test are printed to the console, as shown below:

```
Chi-square statistic: 3.200045474831146
P-value: 0.5249236018493662
There is no significant association between customer rating and on-time delivery. Accept null hypothesis.
Contingency table:
Reached.on.Time_Y.N    0     1
Customer_rating
1                    922  1313
2                    892  1273
3                    882  1357
4                    886  1303
5                    854  1317
```

From the results, we can see that the p-value is greater than 0.05. Therefore, we fail to reject the null hypothesis and conclude that there is no significant association between customer rating and whether the products reached on time.

Also, from the contingency table, we cannot see any clear pattern or association between customer rating and on-time delivery.

## 3.2. Is the cost of the product (column name: Cost_of_the_Product) different among the mode of shipment (column name: Mode_of_Shipment)?

Because there are three or more independent groups categorized by the mode of shipment, we can use the ANOVA test to determine whether there is a significant difference in the cost of the product among the different modes of shipment. We will use the following hypotheses:

- **Null Hypothesis:** The mean cost of the product is the same across all modes of shipment.
- **Alternative Hypothesis:** The mean cost of the product is different across at least one mode of shipment.

We will use a significance level of 0.05. If the p-value is less than 0.05, we can reject the null hypothesis and conclude that there is a significant difference in the mean cost of the product among the different modes of shipment. To calculate the p-value and the test statistic, the following python code will be used:

```python
modes = data['Mode_of_Shipment'].unique()
cost_data = [data[data['Mode_of_Shipment'] == mode]['Cost_of_the_Product'] for mode in modes]

# ANOVA test
f_stat, p_value = stats.f_oneway(*cost_data)

# print results
print('F-statistic:', f_stat)
print('P-value:', p_value)

if p_value < 0.05:
    print('There is a significant difference in the cost of products across different modes of shipment. Reject null hypothesis.')
else:
    print('There is no significant difference in the cost of products across different modes of shipment. Accept null hypothesis.')
```

The results of the ANOVA test are printed to the console, as shown below:

```
F-statistic: 0.368844184436174
P-value: 0.6915417092271512
There is no significant difference in the cost of products across different modes of shipment. Accept null hypothesis.
```

Since the p-value is greater than 0.05, we fail to reject the null hypothesis and conclude that there is no significant difference in the mean cost of the product among the different modes of shipment.