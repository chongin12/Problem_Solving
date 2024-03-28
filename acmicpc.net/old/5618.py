import math
n=int(input())
a=list(map(int,input().split()))
g=math.gcd(a[0],a[1])
if n==3:g=math.gcd(g,a[2])
for i in range(1,g+1):
	if n==2 and a[0]%i==0 and a[1]%i==0:print(i)
	elif n==3 and a[0]%i==0 and a[1]%i==0 and a[2]%i==0:print(i)