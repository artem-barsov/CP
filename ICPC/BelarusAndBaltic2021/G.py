from math import lcm
n, m = map(int, input().split())
print(min(m, lcm(*list(range(2, n+1)))))
