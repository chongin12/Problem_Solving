a=list(map(int,input().split()))
a.sort()
c=a[1]-a[0]
d=a[2]-a[1]
if c==d:
	print(a[2]+d)
elif c*2==d:
	print(a[1]+c)
else:
	print(a[1]-d)