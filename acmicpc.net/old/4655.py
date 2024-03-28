while 1:
	k=input()
	if k=="0.00":break
	n=float(k)
	r=0
	a=2
	while n>r:
		r+=1/a
		a+=1
	print(a-2,"card(s)")