a,b,c=map(int,input().split(':'))
d=0
e=0
if a>0 and a<13:d+=1
elif a>=0 and a<60:e+=1
if b>0 and b<13:d+=1
elif b>=0 and b<60:e+=1
if c>0 and c<13:d+=1
elif c>=0 and c<60:e+=1
r=0
if d+e==3:
	if d==1:r=2
	elif d==2:r=4
	elif d==3:r=6
print(r)