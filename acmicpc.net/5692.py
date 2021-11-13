import sys
while 1:
	n=sys.stdin.readline().rstrip()
	if n=="0":break
	r=0
	for i in range(len(n)):r+=int(n[-(i+1)])*{0:1,1:2,2:6,3:24,4:120}[i]
	print(r)