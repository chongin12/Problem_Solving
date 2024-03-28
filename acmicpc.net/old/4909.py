while 1:
	a=sorted(list(map(float,input().split())))
	if sum(a)<1:break
	print(f"{sum(a[1:5])/4:g}")