n=int(input())
res=0
for i in range(n+1):
	for j in range(i, n+1):
		res+=i+j
print(res)