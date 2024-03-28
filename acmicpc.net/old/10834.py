r=1
d=0
for _ in range(int(input())):
	a,b,c=map(int,input().split())
	d+=c
	r=(r//a)*b
print(d%2,r)