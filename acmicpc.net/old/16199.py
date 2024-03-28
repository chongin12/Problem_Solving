a,b,c=map(int,input().split())
d,e,f=map(int,input().split())
if b==e:
	if c<=f:
		print(d-a)
	else:
		print(d-a-1)
else:
	if b<=e:
		print(d-a)
	else:
		print(d-a-1)
print(d-a+1)
print(d-a)