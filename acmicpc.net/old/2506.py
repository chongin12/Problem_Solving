k=0
r=0
n=int(input())
l=list(input().split())
for i in range(n):
	if l[i]=='1':
		k+=1
		r+=k
	else:
		k=0
print(r)