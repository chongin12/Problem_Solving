n,k=map(int,input().split())
l=list(map(int,input().split(',')))
for i in range(k):
	for j in range(1,n-i):
		l[j-1]=l[j]-l[j-1]
t=""
for i in l[:n-k]:t+=f",{i}"
print(t[1:])