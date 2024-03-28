a,b=map(int,input().split())
i=0
while 1:
	i+=1
	if a*i%b==1:
		print(i)
		break