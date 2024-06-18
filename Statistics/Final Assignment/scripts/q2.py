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