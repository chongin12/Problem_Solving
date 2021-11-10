a=int(input())
for i in range(a):
	b=float(input())
	b=b*0.8
	print("$"+str('%0.2f' % round(b,2)))