n=int(input())
r=int(input())
m=r
for i in range(n):
	a,b=map(int,input().split())
	r=r+a-b
	if r<0:m=99999
	m=max(m,r)
if m==99999:print(0)
else:print(m)
	