while True:
	a=list(map(int,input().split()))
	if a[0]==0:
		break
	r=1
	for i in range(a[0]):
		r*=a[2*i+1]
		r-=a[2*i+2]
	print(r)