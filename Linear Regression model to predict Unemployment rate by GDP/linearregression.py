import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.model_selection import train_test_split
filepath = "dataset.csv"
data = pd.read_csv(filepath)
X = data[['GDP']]
Y = data ['Unemployment rate']

X_Train, X_Test, Y_Train, Y_Test = train_test_split(X, Y, test_size = 0.2, random_state = 42)

model = LinearRegression()
model.fit(X_Train, Y_Train)

Y_Pred = model.predict(X_Test)
##print(Y_Pred)

mse = mean_squared_error(Y_Test, Y_Pred)
r2 = r2_score(Y_Test, Y_Pred)

print(f"MSE ={mse}")
print(f"r2 Score ={r2}")

while True:
    try:
        # Input a new X value
        x_input = float(input("Enter an X value to predict Y (or type 'exit' to quit): "))
        x_input_reshaped = np.array([[x_input]])  # Reshaped to 2D
        # Predict the corresponding Y value using the trained model
        y_prediction = model.predict([[x_input]])
        
        print(f"Predicted Y value for X = {x_input} is: {y_prediction[0]}")

    except ValueError:
        print("Please enter a valid number for X value.")