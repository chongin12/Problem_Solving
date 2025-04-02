n,l=map(int,input().split())
l*=2
li=list(map(int,input().split()))
li.sort()
s=set()
res=0
k1=0
k2=0
for i in li:
    a=i*2
    if a+1>k2:
        k2=max(k2+l,a-1+l)
        res+=1

print(res)