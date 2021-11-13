n=int(input())
r=0
for i in range(1,501):
	for j in range(i+1,501):
		if i**2+n==j**2:r+=1
print(r)