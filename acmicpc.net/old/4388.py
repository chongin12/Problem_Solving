while True:
	a,b=map(int,input().split())
	if a==0 and b==0:
		break
	if a<b:
		a,b=b,a
	j,r,o=[1,0,0]
	while a//j!=0 or b//j!=0:
		if o+a//j%10+b//j%10>9:
			o=1
			r+=1
		else:
			o=0
		j*=10
	print(r)