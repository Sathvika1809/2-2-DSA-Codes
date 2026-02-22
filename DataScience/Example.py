from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
#Load
X,y = load_breast_cancer(return_X_y=True)
#Split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size = 0.2)
#Scale
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)
#Train
model = LogisticRegression()
model.fit(X_train,y_train)
#Predict
y_pred = model.predict(X_test)
print(y_pred)
#Evaluate
accuracy = accuracy_score(y_test,y_pred)
print("Accuracy: ",accuracy)