import matplotlib.pyplot as plt
import numpy as np

x = np.array([2023,2024,2025,2026])
y1 = np.array([15,25,30,20])
y2 = np.array([17,23,38,5])
y3 = np.array([13,15,20,30])
# U can create A dict with all these keyword arguments

line_style = dict(marker=".",
                  markersize=10,
                  markerfacecolor="#fcba03",
                  linestyle="-",
                  linewidth=4)
plt.plot(x,y1,color = "#1414cc",**line_style)
plt.plot(x,y2,color =  "#1461cc",**line_style)
plt.plot(x,y3,color =  "#14cc30",**line_style)
plt.show()