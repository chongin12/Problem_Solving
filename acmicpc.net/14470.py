a=int(input())
b=int(input())
c=int(input())
d=int(input())
e=int(input())
res=0
if a<0:
	res+=c*-a
	a=0
if a==0:
	res+=d
res+=e*(b-a)
print(res)