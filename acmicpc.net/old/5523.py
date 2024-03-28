a,b=[0,0]
for _ in range(int(input())):
	c,d=map(int,input().split())
	if c>d:a+=1
	elif c<d:b+=1
print(a,b)