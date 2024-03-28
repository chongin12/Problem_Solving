a,b=map(int,input().split())
if a>b:
	a,b=b,a
print((a+b)*(b-a+1)//2)