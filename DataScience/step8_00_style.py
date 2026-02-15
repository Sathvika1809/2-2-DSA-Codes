import matplotlib.pyplot as plt

x = [1, 2, 3, 4]
y = [2, 4, 6, 8]

fig ,ax = plt.subplots()
ax.plot(x, y)
ax.set_title("OO Style Plot")
ax.set_xlabel("X")
ax.set_ylabel("Y")

plt.show()
