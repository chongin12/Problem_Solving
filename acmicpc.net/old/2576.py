r=0
m=100
for _ in range(7):
	n=int(input())
	if n%2==1:
		r+=n
		m=min(m,n)
if r==0:
	print(-1)
else:
	print(r)
	print(m)