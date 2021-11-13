for _ in range(int(input())):
	n=int(input())
	for i in range(n):
		for j in range(n):
			print(f"{'#' if i==0 or i==n-1 or j==0 or j==n-1 else 'J'}",end='')
		print()
	print()