n=int(input())
for i in range(n-1):
	print("*"*(i+1)+" "*(n-1-i)*2+"*"*(i+1))
for i in range(n):
	print("*"*(n-i)+" "*i*2+"*"*(n-i))