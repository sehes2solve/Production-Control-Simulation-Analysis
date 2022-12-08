import matplotlib.pyplot as plt
import numpy as np

Demand = np.random.uniform(0, 1, 500)

Profit_1 = list()
Profit_2 = list()

First_Average = 0
Second_Average = 0


for Units in range(2):
    available = 0
    for i in range(500):
        available = available + Units + 1
        x = 0
        if Demand[i] < 0.2:
            x = 0
        elif Demand[i] < 0.6:
            x = 1
        elif Demand[i] < 0.8:
            x = 2
        elif Demand[i] < 0.9:
            x = 3
        else:
            x = 4

        sales = 0
        Cost = 0

        if x > available:
            sales = available
            Cost = (x-available)*100
            available = 0
        elif x < available:
            sales = x
            Cost = (available-x)*50
            available = available - x
        else:
            sales = x
            available = 0

        P = sales*450 - Cost

        if Units == 0:
            First_Average = (First_Average + P) / 2
            Profit_1.append(P)

        elif Units == 1:
            Second_Average = (Second_Average + P) / 2
            Profit_2.append(P)

First_Average = sum(Profit_1) / 500
Second_Average = sum(Profit_2) / 500

print("Average (1 Unit):", First_Average)
print("Average (2 Unit):", Second_Average)

if First_Average > Second_Average:
    print("The Best Decision is to order 1 Unit")
else:
    print("The Best Decision is to order 2 Units")

plt.hist(Profit_1)
plt.show()

plt.hist(Profit_2)
plt.show()

