import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import time
from sklearn.preprocessing import StandardScaler
from sklearn.datasets import fetch_california_housing
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error,mean_absolute_error,r2_score
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
df = pd.read_csv(r"C:\Users\sathv\OneDrive\Desktop\code\Project1\.venv\Lib\site-packages\sklearn\datasets\data\wine_data.csv")
print(df.head())
print(df.info())