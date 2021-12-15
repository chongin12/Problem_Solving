n,i,t=int(input())
i=1
t=0
while n>0:
	if i>n:
		i=1
		continue
	n-=i
	i+=1
	t+=1
print(t)