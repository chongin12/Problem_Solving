for _ in range(int(input())):
	a,b=map(int,input().split())
	r=0
	for i in range(1,a):
		for j in range(i+1,a):
			if (i**2+j**2+b)%(i*j)==0:r+=1
	print(r)