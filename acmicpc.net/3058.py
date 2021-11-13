import sys
t=int(sys.stdin.readline().rstrip())
for _ in range(t):
	a=list(map(int,sys.stdin.readline().rstrip().split()))
	res=0
	m=999
	for i in a:
		if i%2==0:
			m=min(m,i)
			res+=i
	print(res,m)