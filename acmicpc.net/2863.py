a,b=map(int,input().split())
c,d=map(int,input().split())
m=-1
r=0
if a/c+b/d>m:
	m=a/c+b/d
if c/d+a/b>m:
	m=c/d+a/b
	r=1
if d/b+c/a>m:
	m=d/b+c/a
	r=2
if b/a+d/c>m:
	r=3
print(r)