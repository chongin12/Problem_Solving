while 1:
	a,b=input().split()
	c,d=map(int,a.split(':'))
	e,f=map(int,b.split(':'))
	if c+d+e+f==0:break
	g,h=c+e,d+f
	if h>59:
		g+=1
		h-=60
	if g//24>0:print(f"{g%24:02d}:{h:02d} +{g//24}")
	else:print(f"{g%24:02d}:{h:02d}")