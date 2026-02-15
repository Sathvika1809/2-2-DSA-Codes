import numpy as np
import matplotlib.pyplot as plt
x = [0,1,2,3,4]
y = [0,2,4,6,8]
#Resize the graph
plt.figure(figsize=(5,3),dpi=100)
plt.plot(x,y,'r^--',label='2x')
#Line Number Two

x2 = np.arange(0,4.5,0.5)
#print(x2)
plt.plot(x2[:5],x2[:5]**2,'b',label ='X^2')
plt.plot(x2[4:],x2[4:]**2,'g--')
plt.title('Our First Graph!',fontdict={'fontname':'Comic Sans MS','fontsize':20})
plt.xlabel('X Axis')
plt.ylabel('Y Axis')
plt.xticks([0,1,2,3,4])
plt.yticks([0,2,4,6,8,10])
plt.legend()

# labels = ['A','B','C']
# values = [1,4,2]
# plt.bar(labels,values)
# plt.show()
