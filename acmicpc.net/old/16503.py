a,i,b,j,c=input().split()
k=1
if int(a)<0:
	a=str(-int(a))
	k=-k
if int(b)<0:
	b=str(-int(b))
	k=-k
if int(c)<0:
	c=str(-int(c))
	k=-k
e=f"{int(eval('('+a+i+b+')'))}"
q=int(eval(e+j+c))*k
r=f"{int(eval('('+b+j+c+')'))}"
w=int(eval(a+i+r))*k
print(min(q,w))
print(max(q,w))