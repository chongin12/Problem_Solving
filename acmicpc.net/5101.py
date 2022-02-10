while 1:
	a,b,c=map(int,input().split())
	if a==0 and b==0 and c==0:break
	if (b>0 and a>c) or (b<0 and a<c) or (b==0 and a!=c):print('X')
	elif b==0 and a==c:print(1)
	elif (c-a)%b==0:print((c-a)//b+1)
	else:print('X')