n,a,b=map(int,input().split())
m=-1
a-=1
b-=1
x=0
for i in range(n):
	l=list(map(int,input().split()))
	if a==i:
		for j in range(n):
			if j==b:
				x=l[j]
				continue
			m=max(m,l[j])
	else:m=max(m,l[b])
if m>x:
	print("ANGRY")
else:
	print("HAPPY")