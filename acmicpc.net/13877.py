for _ in range(int(input())):
	a,b=input().split()
	c,d=[0,0]
	try:
		c=int('0o'+b,8)
	except:
		c='0'
	print(f"{a} {c} {int(b)} {int('0x'+b,16)}")