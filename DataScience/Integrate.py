import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("diabetes.csv")
type_count = df["Pregnancies"].value_counts(ascending=False)
plt.barh(type_count.index,type_count.values)
plt.title("# of Pokemon by Primary Type")
plt.xlabel("Count")
plt.ylabel("Type")
plt.tight_layout()
plt.show()