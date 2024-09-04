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

print('\n')

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