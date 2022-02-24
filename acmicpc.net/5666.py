while 1:
	try:
		a,b=map(float, input().split())
		print(f"{a/b:.2f}")
	except:
		break