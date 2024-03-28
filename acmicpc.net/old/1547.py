i=1
for _ in range(int(input())):
	b,c=map(int,input().split())
	if b==i:
		i=c
	elif c==i:
		i=b
print(i)