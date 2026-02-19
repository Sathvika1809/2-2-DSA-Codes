import pandas as pd
import numpy as np
import seaborn as sns
from sklearn.preprocessing import MinMaxScaler, StandardScaler
import matplotlib.pyplot as plt

print(pd.__version__)

df = pd.read_csv(r'D:\ML files\diabetes.csv')
#print(df.head())
print(df.info())#Prints concise summary(non-null entries,datatype of each col)
print(df.isnull().sum())#Returns no.of missing values per column
#Statistical summary
#mean,median,std,min/max,quartiles
df.describe()
fig,axs = plt.subplots(len(df.columns),1,figsize=(7,18),dpi=95)
for i,col in enumerate(df.columns):
    axs[i].boxplot(df[col],vert=False)#vert False means horizontal boxplot
    axs[i] #use ith subplot
    axs[i].set_ylabel(col)
plt.tight_layout()
plt.show()
#   Step4 Remove Outliers(Using IQR method)
q1, q3 = np.percentile(df['Insulin'],[25,75])
iqr = q3-q1
lower = q1 - 1.5 * iqr
upper = q3 + 1.5 * iqr
clean_df = df[(df['Insulin']>=lower)&(df['Insulin']<=upper)]
# Keeping bounds to improve model robustness
# Outliers can distort scaling(MinMaxScaler badly affected)
# shift mean/variance,reduce model accuracy
# Correlation Analysis
#corr = df.corr()
#plt.figure(dpi=130)
#sns.heatmap(corr,annot=True,fmt='.2f',cmap='coolwarm')
#plt.show()
#print(corr['Outcome'].sort_values(ascending=False))
# explode = (0,0.1,0,0)
plt.pie(df['Outcome'].value_counts(),labels=['Diabetes','Not Diabetes'],autopct='%1.1f%%',shadow=True)
plt.title('Outcome Proportionality')
plt.show()
