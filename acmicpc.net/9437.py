while 1:
	n=input()
	if n=="0":break
	a,b=map(int,n.split())
	a+=1
	if b%2==1:print(*sorted([b+1,a-b-1,a-b]))
	else:print(*sorted([b-1,a-b,a-b+1]))