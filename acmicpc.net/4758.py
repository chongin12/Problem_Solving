while 1:
	a,b,c=map(float,input().split())
	if a+b+c<1:break
	r=""
	d=0
	if a<=4.5 and b>=150 and c>=200:
		r+="Wide Receiver "
		d=1
	if a<=6.0 and b>=300 and c>=500:
		r+="Lineman "
		d=1
	if a<=5.0 and b>=200 and c>=300:
		r+="Quarterback "
		d=1
	if d==0:r+="No positions"
	print(r)