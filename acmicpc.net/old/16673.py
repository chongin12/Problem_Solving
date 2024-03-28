c,k,p=map(int,input().split())
r=0
for i in range(c+1):
	r+=k*i+p*(i**2)
print(r)