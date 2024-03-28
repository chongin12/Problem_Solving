a,b=map(int,input().split())
c=a//b
d=a%b
if a!=0 and b<0 and d!=0:
	c+=1
	d-=b
print(c)
print(d)