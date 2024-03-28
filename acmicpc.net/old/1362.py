i=0
while 1:
	i+=1
	a,b=map(int,input().split())
	if a==b==0:break
	while 1:
		o,k=input().split()
		w=int(k)
		if o=="#":
			if b>a/2 and b<a*2:print(f"{i} :-)")
			elif b<=0:print(f"{i} RIP")
			else:print(f"{i} :-(")
			break
		if o=="F":b+=w
		else:b-=w
		if b<=0:b=-9999999999