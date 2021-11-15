n,m=map(int,input().split())
a=list(map(int,input().split()))
r=1
for i in a:
	r=((r%m)*(i%m))%m
print(r)