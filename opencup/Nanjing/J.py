t = int(input())
for i in range(t):
    print(2 ** len([eins for eins in bin(int(input())-1)[2:] if eins=='1']))
