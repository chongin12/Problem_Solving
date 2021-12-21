a=int(input())
m=-1
c=0
l=[]
for i in range(a):
	k=int(input())
	l.append(k)
	if k>m:
		m=k
		c+=1
print(c)
c=0
m=-1
for i in range(a-1,-1,-1):
	if l[i]>m:
		m=l[i]
		c+=1
print(c)