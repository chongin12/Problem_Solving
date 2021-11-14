d={}
k=0
for i in list(map(int,input().split())):
	k+=1
	d[i]=k
a,b,c=map(int,input().split())
if a in d:print(d[a])
else:print(0)