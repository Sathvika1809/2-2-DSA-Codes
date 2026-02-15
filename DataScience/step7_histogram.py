import matplotlib.pyplot as plt

marks = [60, 70, 80, 90, 85, 75, 65]

plt.hist(marks, bins=10)
plt.title("Marks Distribution")
plt.show()
