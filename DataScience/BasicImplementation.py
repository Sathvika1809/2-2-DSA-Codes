import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import time
from sklearn.preprocessing import StandardScaler
from sklearn.datasets import fetch_california_housing
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error,mean_absolute_error,r2_score
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
from tensorflow.keras import models
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

data = fetch_california_housing()
X = data.data
y = data.target
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.2,random_state=42)
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

input_shape = (X_train.shape[1],)
model_1 = keras.Sequential([
    layers.Dense(32,activation='relu',input_shape =input_shape),
    layers.Dense(1)
])
model_2 = keras.Sequential([
    layers.Dense(64,activation='relu',input_shape = input_shape),
    layers.Dense(32,activation='relu'),
    layers.Dense(1)
])
model_3 = keras.Sequential([
    layers.Dense(128,activation='relu',input_shape = input_shape),
    layers.Dense(64,activation='relu'),
    layers.Dense(32,activation='relu'),
    layers.Dense(1)
])
for model in [model_1, model_2, model_3]:
    model.compile(
        optimizer='adam',
        loss='mse',
        metrics=['mae']
    )
results=[]
histories=[]
predictions=[]
residuals=[]
for i,model in enumerate([model_1,model_2,model_3]):
    start = time.time()
    history = model.fit(
        X_train,y_train,
        epochs=5,
        batch_size=32,
        verbose=0
    )
    histories.append(history)
    end = time.time()
    training_time = end-start
    y_pred = model.predict(X_test,verbose=0)
    predictions.append(y_pred)
    r2 = r2_score(y_test, y_pred)
    loss,mae = model.evaluate(X_test,y_test,verbose=0)
    results.append([f"Model{i+1}",model.count_params(),training_time,loss,mae,r2])
for y_pred in predictions:
    res=y_test - y_pred.flatten()
    residuals.append(res)

results_df = pd.DataFrame(results,columns=[
            "Model","Parameters","Training Time","MSE","MAE","r2"])
print(results_df)
for i,history in enumerate(histories):
    plt.plot(history.history['loss'],label=f"Model{i+1}")
plt.title("Training Loss")
plt.xlabel("Epoch")
plt.ylabel("Loss")
plt.legend()
plt.show()
    