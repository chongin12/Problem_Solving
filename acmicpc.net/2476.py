n=int(input())
m=-1
for _ in range(n):
	a,b,c=map(int,input().split())
	if a==b and b==c:
		m=max(m,10000+1000*a)
	elif a==b or b==c or c==a:
		m=max(m,1000+100*(a if a==b else c))
	else:
		m=max(m,100*max(a,b,c))
print(m)