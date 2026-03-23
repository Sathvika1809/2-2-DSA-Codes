import matplotlib.pyplot as plt
import numpy as np
#Histogram - visual representation of distribution of quantitative data
#Group values into bins
#and counts how many fall in each range
#U can even select no.of bins u want

scores = np.random.normal(loc=80,scale=10,size = 100)
scores = np.clip(scores, 0,100) # Bound for scores below 0 and 100 to have the value to be 0 and 100 respectively

plt.hist(scores,bins = 10,
         color="lightgreen",
         edgecolor="black")
plt.title("Scores of Students")
plt.xlabel("Scores")
plt.ylabel("Frequency")
plt.show()

