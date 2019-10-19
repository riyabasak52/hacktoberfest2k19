import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
dataset=pd.read_csv('Salary_data.csv')
x=dataset.iloc[0:19,:-1]
y=dataset.iloc[0:19,1]
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.2,random_state=0)
from sklearn.linear_model import LinearRegression
regressor=LinearRegression();
regressor.fit(x_train,y_train)
y_pred=regressor.predict(x_test)

