import sys
r=0
for _ in range(int(sys.stdin.readline().rstrip())):
	r+=int(sys.stdin.readline().rstrip())-1
print(r+1)