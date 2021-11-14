for _ in range(int(input())):
	n,k=map(int,input().split())
	a=list(map(int,input().split()))
	r=0
	for i in a:
		r+=i//k
	print(r)