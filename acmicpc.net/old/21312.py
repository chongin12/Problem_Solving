a,b,c=map(int,input().split())
r=1
if a%2==b%2==c%2:r=a*b*c
else:
	if a%2==1:r*=a
	if b%2==1:r*=b
	if c%2==1:r*=c
print(r)