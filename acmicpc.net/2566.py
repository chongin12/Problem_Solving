m=-1
n=0
r=0
for _ in range(9):
	for i in list(map(int,input().split())):
		if i>m:
			m=i
			r=n
		n+=1
print(m)
print(r//9+1,r%9+1)