n,k,t=map(int,input().split())
res=0
l=list(map(int,input().split()))
for i in l:
    if t<k:
        t=t+i+abs(t-k)
    elif t>k:
        t=t+i-abs(t-k)
    else:
        t=t+i
    res+=abs(t-k)
print(res)