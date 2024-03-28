n=int(input())
r=0
def f(x):
	c=0
	while x>0:
		c+=x%10
		x//=10
	return c
for i in range(1,n+1):
	if i%f(i)==0:r+=1
print(r)