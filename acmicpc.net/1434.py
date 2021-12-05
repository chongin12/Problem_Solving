n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
r=0
for i in b:
	for j in range(len(a)):
		if a[j]==-1:continue
		if a[j]>=i:
			a[j]-=i
			break
		else:
			r+=a[j]
			a[j]=-1;
			continue
for i in a:
	if i!=-1:r+=i
print(r)