for i in range(100):
    if (i&1==0) and (i % 7 == 0) and ((str(i)[0]=='9') or (str(i)[-1]=='9')):
        print(i)
