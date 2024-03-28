for _ in range(int(input())):
	r=0
	for _ in range(int(input())):
		a,b,c=map(int,input().split())
		r+=max(0,a,b,c)
	print(r)