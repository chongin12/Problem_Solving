a,b=map(int,input().split())
for _ in range(a):
	c,d=map(int,input().split())
	if c!=d:
		print("Wrong Answer")
		exit()
for _ in range(b):
	c,d=map(int,input().split())
	if c!=d:
		print("Why Wrong!!!")
		exit()
print("Accepted")