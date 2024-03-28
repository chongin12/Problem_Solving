while True:
	a=input()
	res=0
	if a=="0":
		break
	for i in a:
		if i=='0':
			res+=4
		elif i=='1':
			res+=2
		else:
			res+=3
	res+=len(a)+1
	print(res)