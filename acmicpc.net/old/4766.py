n=float(input())
while True:
	a=float(input())
	if a==999:
		break
	print('{:.2f}'.format(a-n,2))
	n=a