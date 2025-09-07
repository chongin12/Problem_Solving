n=int(input())
p,q,r,s=map(int,input().split())
a=[0 for i in range(60)]
a[1]=int(input())
for i in range(1,n+1):
    a[2*i]=p*a[i]+q
    a[2*i+1]=r*a[i]+s
res=0
for i in range(n+1):
    res+=a[i]
print(res)