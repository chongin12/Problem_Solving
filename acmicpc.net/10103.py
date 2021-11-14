x=100
y=100
for _ in range(int(input())):
	a,b=map(int,input().split())
	if a<b:x-=b
	if a>b:y-=a
print(f"{x}\n{y}")