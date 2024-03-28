while 1:
	n=int(input())
	if n==-1:break
	p=0
	r=0
	for i in range(n):
		a,b=map(int,input().split())
		r+=a*(b-p)
		p=b
	print(r,"miles")