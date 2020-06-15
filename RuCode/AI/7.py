import numpy as np
tasks = np.array([0 for _ in range(25)])

tasks[5:9 +1] += 1
tasks[5:14+1] += 1
tasks[5:24+1] += 1

# tasks[5] -= 1

x = 0
for i in range(5, 25):
    x += i * tasks[i]

print(x, tasks.sum(), x / tasks.sum())
