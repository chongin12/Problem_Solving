for i in range(3):
	a,b=input().split()
	r=0
	c=int(a[0:2])*3600+int(a[3:5])*60+int(a[6:8])
	d=int(b[0:2])*3600+int(b[3:5])*60+int(b[6:8])
	if c>d:d+=86400
	for i in range(c,d+1,1):
		if (i%60+(i//60)%60*100+(i//3600)%24*10000)%3==0:r+=1
	print(r)