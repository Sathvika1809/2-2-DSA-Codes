import matplotlib.pyplot as plt
import numpy as np
#Figure = the entire canvas
#Ax = A single plot(Subplot)
x = np.array([1,2,3,4,5])
figure, axes = plt.subplots(2,2)
#This essentially returns a subplots of rows and cols mentioned
#The return type is Figure,Axes
axes[0,0].plot(x,x*2,color='red')
axes[0,0].set_title("x*2")
print("\n")
axes[0,1].plot(x,x**2,color='blue')
axes[0,1].set_title("x**2")
print("\n")
axes[1,0].plot(x,x**3,color="green")
axes[1,0].set_title("x**3")
print("\n")
axes[1,1].plot(x,x,color='purple')
axes[1,1].set_title("x-x")

plt.show()