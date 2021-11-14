for i in range(int(input())):
	print(f"Scenario #{i+1}:")
	a,b,c=map(int,input().split())
	m=max(a,b,c)
	if a==m:print(f"{'yes' if a<b+c and b**2+c**2==a**2 else 'no'}")
	elif b==m:print(f"{'yes' if b<a+c and a**2+c**2==b**2 else 'no'}")
	else:print(f"{'yes' if c<a+b and a**2+b**2==c**2 else 'no'}")
	print()