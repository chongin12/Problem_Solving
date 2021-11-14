n=-2
while 1:
	n+=1
	b=1
	for i in range(2,1001):
		if n%i!=i-1:
			b=0
			break
	if b:
		print(n)
		break