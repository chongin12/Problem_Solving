n=int(input())
r=0
for i in range(2,n-1,2):
	r+=(n-i-2)//2
print(r)