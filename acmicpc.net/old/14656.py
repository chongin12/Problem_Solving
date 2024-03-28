n=int(input())
a=list(map(int,input().split()))
r=0
for i in range(n):
	if i+1!=a[i]:r+=1
print(r)