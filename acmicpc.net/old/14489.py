a,b=map(int,input().split())
c=a+b
n=int(input())
if c>=n*2:
	c-=n*2
print(c)