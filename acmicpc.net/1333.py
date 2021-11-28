n,l,d=map(int,input().split())
r=0
i=0
while n>0:
	n-=1
	i+=l
	for j in range(5):
		if i%d==0:
			print(i)
			exit(0)
		i+=1
while 1:
	if i%d==0:
		print(i)
		exit(0)
	i+=1