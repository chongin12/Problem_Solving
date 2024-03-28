while 1:
	a,b,c,d=map(int,input().split())
	if a==0:break
	e=min(c/a,d/b)*100
	f=min(c/b,d/a)*100
	print(f"{min(int(max(e,f)),100)}%")