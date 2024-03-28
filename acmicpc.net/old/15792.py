a,b=map(int,input().split())
r=f"{a//b}."
for i in range(1000):
	a=(a%b)*10
	r+=f"{a//b}"
print(r)