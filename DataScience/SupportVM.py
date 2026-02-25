from sklearn import svm
X = [
    [-3,-1],
    [0,-2],
    [-2.5,2],
    [-1,-1],
    [3,0.5],
    [0.5,3],
    [-3,-3],
]
#labels
y = [0,1,0,1,1,0,1]
#fit
clf = svm.SVC(kernel = 'linear').fit(X,y)
#predict
y_pred = clf.predict([[2,4]]) >= 0
print(y_pred)