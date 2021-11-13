while True:
	a,b=map(int,input().split())
	if a==0 and b==0:
		break
	c=round(a**(1.0/b))-1
	d=c**b
	for _ in range(2):
		if abs(a-d)>abs(a-(c+1)**b):
			d=(c+1)**b
			c+=1
	print(c)