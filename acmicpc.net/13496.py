T=int(input())
for i in range(T):
    n,s,d=map(int,input().split())
    r=0
    for j in range(n):
        di,vi=map(int,input().split())
        if di%s==0:
            if d>=di//s:r+=vi
        else:
            if d>=di//s+1:r+=vi
    print(f"Data Set {i+1}:")
    print(r)
    print()
