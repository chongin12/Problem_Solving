res=-1
for _ in range(2):
	a,b,c,d=map(int,input().split())
	res=max(res,a+b+c+d)
print(res)