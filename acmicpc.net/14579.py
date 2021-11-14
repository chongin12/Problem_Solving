a,b=map(int,input().split())
r=1
for i in range(a,b+1):
	r*=((i+1)*i//2)%14579
	r%=14579
print(r)