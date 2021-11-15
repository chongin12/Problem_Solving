for _ in range(int(input())):
	n,m=map(int,input().split())
	if n>=12 and m>=4:print(m*11+4)
	else:print(-1)