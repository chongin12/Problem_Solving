n=int(input())
l=list(map(int,input().split()))
d=dict()
maxK=0
for i in range(51):
    d[i]=0
for i in l:
    d[i]=d[i]+1
    maxK=max(maxK,i)
res=0
for k in range(1,maxK+1):
    r=1
    for i in range(1,k+1):
        r=r*d[i]
    res+=r
print(res)