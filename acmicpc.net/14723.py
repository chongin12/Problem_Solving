n=int(input())
k=1
while n>0:
	n-=k
	k+=1
a=k-(n+k-1)
print(a,k-a)