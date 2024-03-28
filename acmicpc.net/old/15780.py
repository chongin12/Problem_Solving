n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in a:
	n-=(i+1)//2
print("YES") if n<=0 else print("NO")