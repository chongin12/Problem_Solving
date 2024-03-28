while 1:
	try:
		a,b=map(int,input().split())
		res=a
		while a>=b:
			res+=a//b
			a=a%b+a//b
		print(res)
	except:break