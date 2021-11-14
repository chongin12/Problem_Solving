while 1:
	m,a,b=map(int,input().split())
	if m+a+b==0:break
	m*=100
	r=round(m*36/a-m*36/b)
	print(f"{r//3600}:{r%3600//60:02d}:{r%60:02d}")