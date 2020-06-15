c = 0

def f(n):
    global c
    if n == 0:
        # print(c)
        return 1
    else:
        index = n - 1
        sum = 1
        while (index >= 0):
            sum = sum + f(index)
            c += 1
            index = index - 1
        print(c)
        return sum
f(30)
