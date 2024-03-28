n=int(input())
l=list(map(int,input().split()))
c=int(input())
res=0
for i in l:
	if i%c!=0:i+=c
	res+=i//c
print(res*c)