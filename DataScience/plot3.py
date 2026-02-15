import matplotlib.pyplot as plt
x = [1,2,3,4]
y1 = [10,20,30,40]
y2 = [15,25,35,45]
#y = [3,6,9,12]
plt.plot(x,y1,label = "Line 1")
plt.plot(x,y2,label = "Line 2")
# plt.plot(x,y,color = 'red',linestyle = '--',marker = 'o')
# plt.title("Styled Line Plot")

plt.legend()
plt.title("Multiple Lines")
#plt.bar(x,y1)
plt.show()