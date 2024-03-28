l,r,a=map(int,input().split())
if l<r:
	l+=a
	if l>r:print((l+r)//2*2)
	else:print(min(l,r)*2)
else:
	r+=a
	if(l<r):print((l+r)//2*2)
	else:print(min(l,r)*2)