for _ in range(3):
	a,b,c,d=map(int,input().split())
	m=a+b+c+d
	if m==0:
		print("D")
	elif m==1:
		print("C")
	elif m==2:
		print("B")
	elif m==3:
		print("A")
	else:
		print("E")