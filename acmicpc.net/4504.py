n=int(input())
while True:
	a=int(input())
	if a==0:
		break
	print(f"{a} is {'' if a%n==0 else 'NOT '}a multiple of {n}.")