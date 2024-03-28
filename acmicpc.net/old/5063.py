a=int(input())
for i in range(a):
	b,c,d=map(int,input().split())
	e=c-d
	if b<e:print("advertise")
	elif b>e:print("do not advertise")
	else:print("does not matter")