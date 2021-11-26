a,b,c=map(int,input().split())
l=[0 for i in range(a+b+c+4)]
m=0
M=0
for i in range(a):
	for j in range(b):
		for k in range(c):
			l[i+j+k+3]+=1
			if l[i+j+k+3]>m:
				m=l[i+j+k+3]
				M=i+j+k+3
print(M)