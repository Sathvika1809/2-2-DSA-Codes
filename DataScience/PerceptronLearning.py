import numpy as np
import matplotlib.pyplot as plt
import random
#Inputs and Labels
x=[
  [0.72,0.82,-1],
  [0.91,-0.69,-1],
  [0.03,0.93,-1],
  [0.12,0.25,-1],
  [0.96,0.47,-1],
  [0.8,-0.75,-1],
  [0.46,0.98,-1],
  [0.66,0.24,-1],
  [0.72,-0.15,-1],
  [0.35,0.01,-1],
  [-0.11,0.1,1],
  [0.31,-0.96,1],
  [0,-0.26,1],
  [-0.43,-0.65,1],
  [0.57,-0.97,1],
  [-0.72,-0.64,1],
  [-0.25,-0.43,1],
  [-0.12,-0.9,1],
  [-0.58,0.62,1],
  [-0.77,-0.76,1]
]
#Output
y=0
BEST_X = 0.77
BEST_Y = -0.55
color = ""
answer = ""
data_dictionary = {
    #'Keys':'Values',
    '0.72,0.82':'-1',
    '0.91,-0.69':'-1',
    '0.03,0.93':'-1',
    '0.12,0.25':'-1',
    '0.96,0.47':'-1',
    '0.8,-0.75':'-1',
    '0.46,0.98':'-1',
    '0.66,0.24':'-1',
    '0.72,-0.15':'-1',
    '0.35,0.01':'-1',
    '-0.11,0.1':'1',
    '0.31,-0.96':'1',
    '0,-0.26':'1',
    '-0.43,-0.65':'1',
    '0.57,-0.97':'1',
    '-0.72,-0.64':'1',
    '-0.25,-0.43':'1',
    '-0.12,-0.9':'1',
    '-0.58,0.62':'1',
    '-0.77,-0.76':'1'
}
#Helper Function for plotting red and Blue pts
def get_points(data,label):
    x_coords = [float(point.split(",")[0])for point in data.keys() if data[point]==label]
    y_coords = [float(point.split(",")[1])for point in data.keys() if data[point]==label]
    return x_coords,y_coords
#Parameters
##Step 1
#Weights
w=[0,0]
bias = 1
threshold = 0
learning_rate=1
#Max no. of epochs 
max_iterations=100
plt.ion()
##Step2 : Loop
for k in range(1,max_iterations):
    hits = 0
    print("\n-------------Epoch"+str(k)+"----------------")
    #Send all data points into the learning algorithm
    for i in range(0,len(x)):
        net = 0
        #Weighted Sum
        for j in range(0,len(x[i])-1):# We are doing len-1 because last one is labels and we want only features
            net+=x[i][j]*w[j]
    #Output = bias+weighted sum
        output = bias+net
    #Apply Activation on Output
    #Activation Function = {value>0:1:-1}
        print("---> Data Point Index (Before Wgt Update):",i,
          "Input:",x[i],
          "Weights: ",w,
          " Output sum:", output)
        if output > threshold:
            y=1
        else:
            y=-1
        if y==x[i][2]:
            hits+=1
            answer = "Correct!" #No Weight Change."
        else:
            for j in range (0,len(w)):
                w[j]=w[j]+(learning_rate*x[i][2]*x[i][j])#Formula
            bias = bias+learning_rate*x[i][2]
            answer = "Weight update has happened,New Weight is :"+str(w)
        print("\n"+answer)
    #Plotting the graph Below-----
        plt.clf()
        plt.title('Epoch %s\n'% (str(k)))
        plt.grid(False)#Plot a grid
        plt.xlim(-1,1)
        plt.ylim(-1,1)

        xA = 1
        xB = -1
        if w[1] != 0:
            yA = (-w[0]*xA-bias)/w[1]
            yB = (-w[0]*xB-bias)/w[1]
        else:
            xA = -bias/w[0]
            xB = -bias/w[0]

            yA = 1
            yB = -1
        #Plot the black line,that is,we want to learn the 
        #black line as faithfully as possible
        #(Best decision Boundary)
        plt.plot([BEST_X,BEST_Y],[-1,1],color='k',linestyle='-',linewidth=1)
        plt.plot([xA,xB],[yA,yB],color='g',linestyle='-',linewidth=2)
        #Plot Blue points
        x_coords,y_coords = get_points(data_dictionary,'-1')
        plt.plot(x_coords,y_coords,'bo')
        #Plot red points
        x_coords,y_coords = get_points(data_dictionary,'1')
        plt.plot(x_coords,y_coords,'ro')
        #Highlights the current point
        if answer == 'Correct!':
            #Correct - with green color
            plt.plot(x[i][0],x[i][1],'go',markersize=15,alpha=0.5)
        else:
            #Incorrect-with magenta color
            plt.plot(x[i][0],x[i][1],'mo',markersize=30,alpha=0.5)
        #Show the plot
        plt.show()
        plt.pause(1)
    if hits == len(x):
        print("\n---------------------------")
        print("\nAlgorithms has learned with"+str(k)+" iterations!")
        break
    else:
        print("\n---------------------------------")
        print("\nAlgorithms has exhausted its epochs and not learned!")
        
print("\nDone!\n")



