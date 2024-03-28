a,b=map(int,input().split())
i=2
while i<b:
	if a%i==0:
		print("BAD",i)
		break
	i+=1
if i==b:
	print("GOOD")