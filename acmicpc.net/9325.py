for _ in range(int(input())):
	s=int(input())
	for _ in range(int(input())):
		a,b=map(int,input().split())
		s+=a*b
	print(s)