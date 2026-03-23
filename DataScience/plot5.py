import matplotlib.pyplot as plt
import numpy as np

#Scatter graph
x1 = np.array([0,1,1,2,3,4,5,6,7,7,8])#Hours studied
y1 = np.array([55,60,65,62,68,70,75,78,82,85,87])#Grades


x2 = np.array([0,1,2,2,3,5,5,6,8,7,8])#Hours studied
y2 = np.array([55,60,62,65,70,72,75,88,90,95,97])#Grades
plt.scatter(x1,y1,color="red",
            s =100,
            label = "Class A")
plt.scatter(x2,y2,color="blue",
            s =100,
            label="Class B")
plt.title("Test Scores")
plt.xlabel("Hours studied")
plt.ylabel("Grades")
plt.legend()
plt.show()