for _ in range(int(input())):
	d=int(input())
	for i in range(d,-1,-1):
		if i*i+i<=d:
			print(i)
			break