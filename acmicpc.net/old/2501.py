a,b=map(int,input().split())
for i in range(1,a+1):
	if a%i==0:
		b-=1
	if b==0:
		print(i)
		break
if b!=0:
	print(0)