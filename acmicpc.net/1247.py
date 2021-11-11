import sys
for _ in range(3):
	n=int(sys.stdin.readline().rstrip())
	res=0
	for i in range(n):
		res+=int(sys.stdin.readline().rstrip())
	if res<0:
		print("-")
	elif res==0:
		print("0")
	else:
		print("+")