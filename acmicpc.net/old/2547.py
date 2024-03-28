for _ in range(int(input())):
	input()
	n=int(input())
	r=0
	for i in range(n):
		r+=int(input())
	if r%n==0:
		print("YES")
	else:
		print("NO")