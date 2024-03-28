a,b,c,d=map(int,input().split())
p,m,n=map(int,input().split())
r1,r2,r3=[0,0,0]
if p%(a+b)<=a and p%(a+b)!=0:
	r1+=1
if p%(c+d)<=c and p%(c+d)!=0:
	r1+=1
if m%(a+b)<=a and m%(a+b)!=0:
	r2+=1
if m%(c+d)<=c and m%(c+d)!=0:
	r2+=1
if n%(a+b)<=a and n%(a+b)!=0:
	r3+=1
if n%(c+d)<=c and n%(c+d)!=0:
	r3+=1
print(r1)
print(r2)
print(r3)