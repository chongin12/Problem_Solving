s,c,l,x=[0,51,180,0]
for i in range(int(input())):
	a,b,p=map(int,input().split())
	if a>s:
		s,c,l,x=[a,b,p,i+1]
	elif a==s:
		if b<c:
			s,c,l,x=[a,b,p,i+1]
		elif b==c:
			if l>p:
				s,c,l,x=[a,b,p,i+1]
print(x)