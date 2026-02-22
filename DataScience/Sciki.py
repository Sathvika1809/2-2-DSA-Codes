from sklearn.datasets import load_iris
iris = load_iris()
X = iris.data
y = iris.target
feature_names = iris.feature_names
target_names = iris.target_names
print("Feature names:",feature_names)
print("Target names:",target_names)
print("\nType of X is:", type(X)) 
print("\nFirst 5 rows of X:\n", X[:5])
#Splitting dataset
#using train test split -> split iris dataset into 60% training and 40% for testing(0.4 test size),random_state=1
#After splitting we get
#X_train,y_train->Training data
#X_test,y_test->Testing data
#Usage
from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.4,random_state = 1)
print("X_train shape: ",X_train.shape)
print("X_test Shape: ",X_test.shape)
print("Y_train Shape: ",y_train.shape)
print("Y_test Shape: ",y_test.shape)
#Label Encoding
#Converts Each Category into a unique Integer
#Cat,dog,bird categories to 0,1,2,LabelEncoder(),fit_transform()
#fit_transform()-first fits the encoder to the categorical data and then transforms 
#the categories into corresponding numeric Labels
from sklearn.preprocessing import LabelEncoder
cat_fea = ['cat','dog','dog','cat','bird']
encoder = LabelEncoder()
encoded_feature = encoder.fit_transform(cat_fea)
print("Encoded Feature: ",encoded_feature)
#Training the Model
#Interface for Training,prediction and evaluation
from sklearn.linear_model import LogisticRegression
log_reg = LogisticRegression(max_iter = 200)
log_reg.fit(X_train,y_train)
#MAKE predictions
y_pred = log_reg.predict(X_test)
print("pred: ",y_pred)
from sklearn import metrics
print("Logistic Regression model accuracy:",metrics.accuracy_score(y_test,y_pred))
#Make Predictions on new Data
sample = [[3,5,4,2],[2,3,5,4]]
preds = log_reg.predict(sample)
pred_species = [iris.target_names[p] for p in preds]
print("Predictions: ",preds)
#Data PreprocessingTraining models,making predictions
#Cross validation and performance metrics
#Binomial Logistic Regression
from sklearn.datasets import load_breast_cancer
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

X, y = load_breast_cancer(return_X_y=True)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20, random_state=23)
clf = LogisticRegression(max_iter=10000, random_state=0)
clf.fit(X_train, y_train)
acc = accuracy_score(y_test, clf.predict(X_test)) * 100
print(f"Logistic Regression model accuracy: {acc:.2f}%")