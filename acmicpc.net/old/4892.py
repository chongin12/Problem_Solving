i=0
while True:
	i+=1
	n=int(input())
	if n==0:
		break
	print(f"{i}. {'odd' if n%2==1 else 'even'} {n//2}")