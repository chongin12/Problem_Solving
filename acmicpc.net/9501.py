for _ in range(int(input())):
	n,d=map(int,input().split())
	r=0
	for i in range(n):
		v,f,c=map(int,input().split())
		if d<=v*(f/c):r+=1
	print(r)