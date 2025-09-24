n,m,a,b=map(int,input().split())
r=3*n-m
if r<=0:print(0)
else:print(r*a+b)