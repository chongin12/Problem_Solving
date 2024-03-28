i=0
while True:
	a,b,c=map(float,input().split())
	if b==0:
		break
	i+=1
	print(f"Trip #{i}: {'{0:.2f}'.format(round((a*3.1415927*b)/(5280*12),2))} {'{0:.2f}'.format(round(((a*3.1415927*b)/(5280*12))/(c/3600),2))}")