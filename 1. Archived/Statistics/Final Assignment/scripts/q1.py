import pandas as pd
import scipy.stats as stats
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from statsmodels.stats.multicomp import pairwise_tukeyhsd

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
    print('There is a significant difference in the mean ages of passengers in different classes. Reject null hypothesis.')
else:
    print('There is no significant difference in the mean ages of passengers in different classes. Accept null hypothesis.')

# tukey test
tukey = pairwise_tukeyhsd(titanic_data['age'], titanic_data['pclass'], alpha=0.05)
print(tukey)
tukey.plot_simultaneous()
plt.title("Tukey HSD Test for Age Differences between Passenger Classes")
plt.xlabel("Age")
plt.ylabel("Passenger Class")
plt.savefig("../pics/q1_tukey.png")
print('\n')

# q2
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