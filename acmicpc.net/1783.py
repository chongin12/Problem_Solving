N,M=map(int,input().split())
N,M=N-1,M-1
if N==0:
    print(1)
    exit(0)
res=0
if N==1:
    res=1+M//2
else:
    res=1+M
res=min(res,4)
res2=0
if N>=2 and M>=6:
    M-=6
    res2=5+M
print(max(res,res2))
