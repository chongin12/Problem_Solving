for _ in range(int(input())):
	c=0
	g=0
	for _ in range(int(input())):
		a,b=map(float,input().split())
		c+=a
		g+=b*a
	print(int(c),round(g/c,1))