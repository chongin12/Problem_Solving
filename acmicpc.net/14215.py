a,b,c=map(int,input().split())
if a+b+c>max(a,b,c)*2:
	print(a+b+c)
else:
	print((a+b+c-max(a,b,c))*2-1)