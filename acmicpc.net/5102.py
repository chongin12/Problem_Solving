while 1:
	a,b=map(int,input().split())
	if a==0 and b==0:break
	c=a-b
	if c<2:print("0 0")
	elif c%2==0:print(f"{c//2} 0")
	else:print(f"{c//2-1} 1")