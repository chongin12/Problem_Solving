a,b=map(int,input().split())
i=1
r=0
while a//i!=0:
	r+=a//i
	i*=b
print(r)