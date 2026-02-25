import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import sklearn
import warnings
from sklearn.preprocessing import LabelEncoder
from sklearn.impute import KNNImputer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import f1_score, mean_squared_error,r2_score
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import cross_val_score
from sklearn.tree import plot_tree
warnings.filterwarnings('ignore')
df = pd.read_csv(r'C:\Users\sathv\Downloads\Position_Salaries.csv')
print(df)
df.info()
#Data Preparation
x = df.iloc[:,1:2].values
y = df.iloc[:,2].values 
label_encoder = LabelEncoder()#converts text categorical data to numbers
x_categorical = df.select_dtypes(include=['object']).apply(label_encoder.fit_transform)
#label_encoder works col by col hence 
#Above line -> select only cols with dtyoe object for each text col->Learn unique values and convert them into nums
x_numerical = df.select_dtypes(exclude=['object']).values
x=pd.concat([pd.DataFrame(x_numerical),x_categorical],axis = 1).values
regressor = RandomForestRegressor(n_estimators=10,random_state=0,oob_score=True) 
regressor.fit(x,y)
oob_score = regressor.oob_score_
print(f'Out-of-Bag Score: {oob_score}')
predictions = regressor.predict(x)
mse = mean_squared_error(y,predictions)
print(f'Mean Squared Error: {mse}')
r2 = r2_score(y,predictions)
print(f'R-squared: {r2}')
X_grid = np.arange(min(x[:,0]),max(x[:,0]),0.01)
X_grid = X_grid.reshape(-1,1)
X_grid = np.hstack((X_grid,np.zeros((X_grid.shape[0],2))))
plt.scatter(x[:,0],y,color='blue',label="Actual Data")
plt.plot(X_grid[:,0],regressor.predict(X_grid),color='green',label="Random Forest Prediction")
plt.title("Random Forest Regression Results")
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.legend()
plt.show()
                                                                                                                                                                                                                                    