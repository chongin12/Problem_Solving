k=int(input())+807
r=210
for i in range(int(input())):
	a,b=input().split()
	r-=int(a)
	if r<=0:
		print(k%8+1)
		break
	if b=="T":k+=1