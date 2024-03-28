n,m,M,t,r=map(int,input().split())
i=0
k=m
if M-m<t:
	print(-1)
	exit(0)
while n>0:
	i+=1
	if k+t>M:k=max(k-r,m)
	else:
		k+=t
		n-=1
print(i)