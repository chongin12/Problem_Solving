n=int(input())
for i in range(n):
	for j in range(n+i):
		print(f"{'*' if j==n+i-1 or j==n-i-1 else ' '}",end='')
	print()