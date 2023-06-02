import math
t=int(input())
for i in range(t):
    n=int(input())
    s=sum(list(map(int,input().split())))
    k=1
    r=1
    while s*k<=n:
        r+=1
        k*=4
    print(r)