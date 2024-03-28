n,t=map(int,input().split())
r=0
a=list(map(int,input().split()))
for i in a:
	t-=i
	if t<0:break
	r+=1
print(r)