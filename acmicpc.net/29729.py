s,n,m=map(int,input().split())
r=0
for _ in range(n+m):
    a=int(input())
    if a==1:
        r+=1
        if s<r:
            s*=2
    else:
        r-=1
print(s)