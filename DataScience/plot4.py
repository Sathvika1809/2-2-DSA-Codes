import matplotlib.pyplot as plt
#barchart
import numpy as np

categories = np.array(["Grains","Fruit","Vegetables","Protein","Dairy","Sweets"])
values = np.array([4,3,2,5,3,1])
plt.bar(categories,values,color="skyblue")
plt.title("Daily Consumption")
plt.xlabel("Food")
plt.ylabel("Quantity")
plt.show()
#Piechart
#CIrcular chart divided to slices

categories1 = np.array(["Freshman","Sophomores","Juniors","Seniors"])
values1=np.array([300,250,275,225])
colors = ["red","yellow","blue","green"]
plt.pie(values1,labels=categories1,
        autopct="%1.1f%%",
        colors = colors,
        explode=[0,0,0,0.1],
        shadow = True,
        startangle = 90)
plt.title("College Bits")

plt.show()

