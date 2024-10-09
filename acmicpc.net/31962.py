n,x=map(int,input().split())
r=-1
for i in range(n):
    a,b=map(int,input().split())
    if a+b<=x:r=max(r,a)
print(r)