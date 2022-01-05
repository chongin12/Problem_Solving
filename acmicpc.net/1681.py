n,l=map(int,input().split())
r=1
def f(n):
	while n>0:
		if n%10==l:return False
		n//=10
	return True
while 1:
	if n==0:break;
	if f(r):n-=1
	r+=1
print(r-1)