import math
i=0
while 1:
	i+=1
	a,b,c=map(int,input().split())
	if a==0 and b==0 and c==0:break
	print(f"Triangle #{i}")
	if a==-1:
		if c**2-b**2<=0:
			print("Impossible.\n")
			continue
		a=math.sqrt(c**2-b**2)
		print("Impossible.") if a+b<=c else print(f"a = {a:.3f}")
	elif b==-1:
		if c**2-a**2<=0:
			print("Impossible.\n")
			continue
		b=math.sqrt(c**2-a**2)
		print("Impossible.") if a+b<=c else print(f"b = {b:.3f}")
	else:
		c=math.sqrt(a**2+b**2)
		print("Impossible.") if a+b<=c else print(f"c = {c:.3f}")
	print()