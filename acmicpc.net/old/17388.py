a,b,c=map(int,input().split())
m=min(a,b,c)
if a+b+c>=100:
	print("OK")
elif a==m:
	print("Soongsil")
elif b==m:
	print("Korea")
else:
	print("Hanyang")