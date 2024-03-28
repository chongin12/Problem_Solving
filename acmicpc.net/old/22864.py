a,b,c,m=map(int,input().split())
r=0
p=0
for i in range(24):
	if p+a<=m:
		p+=a
		r+=b
	else:
		p-=c
		p=max(p,0)
print(r)