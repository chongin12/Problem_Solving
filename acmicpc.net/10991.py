n=int(input())
for i in range(n):
	for j in range(n+i):
		print(f"{'*' if j<=n+i-1 and j>=n-i-1 and j%2==(n-i-1)%2 else ' '}",end='')
	print()