import matplotlib.pyplot as plt
x=[1,2,3,4]
#fig, ax = plt.subplots(1,2)
fig, ax = plt.subplots(1,2,figsize = (8,4))
ax[0].plot(x,[1,2,3,4])
ax[0].set_yticks([1, 2, 3, 4])
ax[0].set_title("Plot 1")
ax[1].plot(x,[4,3,2,1])
ax[1].set_title("Plot 2")
plt.show()
fig,ax = plt.subplots(figsize = (8,4))