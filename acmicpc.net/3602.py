a,b=map(int,input().split())
a,b=min(a,b),max(a,b)
i=0
while 1:
	if i%2==1:
		if (a==b and i*i>a+a-1) or (a!=b and i*i>a+a+1):break
	else:
		if i*i>a+a:break
	i+=1
i-=1
if i==0:print("Impossible")
else:print(i)