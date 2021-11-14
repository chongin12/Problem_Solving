for _ in range(int(input())):
	a,b,c,d=map(int,input().split())
	e=a+b*d
	f=b*c
	if f<e:print("do not parallelize")
	elif f>e:print("parallelize")
	else:print("does not matter")