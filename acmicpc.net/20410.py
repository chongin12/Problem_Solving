m,s,x,y=map(int,input().split())
for i in range(m):
	for j in range(m):
		if x==(i*s+j)%m and y==(i*x+j)%m:
			print(i,j)
			exit()