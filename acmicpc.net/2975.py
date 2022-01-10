while 1:
	a,b,c=input().split()
	if a=="0" and c=="0":break
	if b=="W":
		d=int(a)-int(c)
		if d<-200:print("Not allowed")
		else:print(d)
	else:print(int(a)+int(c))