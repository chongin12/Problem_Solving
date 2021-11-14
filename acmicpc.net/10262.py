a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=0
d=0
for i1 in range(a[0],a[1]+1):
	for i2 in range(a[2],a[3]+1):
		for j1 in range(b[0],b[1]+1):
			for j2 in range(b[2],b[3]+1):
				if i1+i2>j1+j2:c+=1
				if i1+i2<j1+j2:d+=1
if c==d:print("Tie")
elif c>d:print("Gunnar")
else:print("Emma")