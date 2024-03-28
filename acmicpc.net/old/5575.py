import sys
for _ in range(3):
	a,b,c,d,e,f = map(int, sys.stdin.readline().rstrip().split())
	res=3600*d+60*e+f-(3600*a+60*b+c)
	if res<0:
		res+=86400
	print(res//3600, res%3600//60, res%60)