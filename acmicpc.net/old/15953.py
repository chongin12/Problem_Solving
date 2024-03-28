x=[500,300,200,50,30,10]
y=[512,256,128,64,32]
for _ in range(int(input())):
	r=0
	a,b=map(int,input().split())
	if a!=0:
		for i in range(6):
			if a-(i+1)<=0:
				r+=x[i]
				break
			a-=i+1
	if b!=0:
		for i in range(5):
			if b-(2**i)<=0:
				r+=y[i]
				break
			b-=2**i
	print(r*10000)