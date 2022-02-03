while 1:
	try:
		n,w,d,r=map(int,input().split())
		a=n*(n-1)//2*w
		if a==r:print(n)
		else:print((a-r)//d)
	except:break