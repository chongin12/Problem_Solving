n=int(input())
r=0
def f(k):
	c=0
	while k>0:
		if k%10!=0 and k%10%3==0:
			c+=1
		k//=10
	return c
for i in range(1,n+1):
	r+=f(i)
print(r)