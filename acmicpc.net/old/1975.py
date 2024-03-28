import sys
a=int(sys.stdin.readline().rstrip())
for _ in range(a):
	b=int(sys.stdin.readline().rstrip())
	res=0
	for i in range(2,b+1):
		if b%i==0:
			res+=1
			c=i*i
			while c<=b:
				if b%c==0:
					res+=1
				c*=i
	print(res)