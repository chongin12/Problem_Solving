for _ in range(int(input())):
	r=0
	for i in range(int(input())+1):
		r+=i*((i+2)*(i+1)//2)
	print(r)