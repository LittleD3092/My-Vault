import matplotlib.pyplot as plt

# Read the file
data = []
start_time = 0
with open("entropy.txt", "r") as file:
    for line in file:
        x, y = line.strip().split()
        if start_time == 0:
            start_time = float(x)
        data.append((float(x) - start_time, float(y)))

# Extract x and y values
x_values = [point[0] for point in data]
y_values = [point[1] for point in data]

# Plot the data
plt.plot(x_values, y_values)
plt.xlabel("Time (s)")
plt.ylabel("Entropy")
plt.title("Entropy over time")
# Save the plot to a file
plt.savefig("plot.png")