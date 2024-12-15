import pandas as pd
import matplotlib.pyplot as plt

# Load the dataset
file_path = "dataset.csv"
data = pd.read_csv(file_path)

# Extract GDP and Unemployment Rate
x = data['GDP']
y = data['Unemployment rate']

# Add title and labels
plt.title("Stacked Scatter Plot: GDP and Unemployment Rate", fontsize=14)

fig, ax = plt.subplots()
ax.hist(x, bins=20, linewidth=0.5, edgecolor="white")
ax.hist(y, bins=20, linewidth=0.5, edgecolor="white", color= "red")

# Add grid and legend
plt.grid(True)
plt.legend()

# Show the plot
plt.show()
