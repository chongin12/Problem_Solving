for _ in range(int(input())):
	n=int(input())
	print(f"Pairs for {n}:", end='')
	for i in range(1,(n+1)//2):
		print(f"{',' if i!=1 else ''} {i} {n-i}",end='')
	print()