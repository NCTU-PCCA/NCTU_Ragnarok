#!/usr/bin/env python3
import random
t=random.randint(5,10)
print(t)
for _ in range(t):
    n=random.randint(100,200)
    m=random.randint(5,n*n//2)
    print("%d %d"%(n,m))

    mm={}
    for i in range(n+1):
        mm[i]={}
        for j in range(n+1):
            mm[i][j]=False
    for i in range(m):
        while(True):
            x=random.randint(1,n)
            y=random.randint(1,n)
            if x==y: continue
            if mm[x][y]==True: continue
            mm[x][y]=True
            print("%d %d"%(x,y))
            break;
    for i in range(n):
        x=random.randint(0,1)
        print(x,end=" ")
    else:
        print()
    for i in range(n):
        x=random.randint(0,1)
        print (x,end=" ")
    else:
        print



