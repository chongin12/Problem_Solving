a=input()
c=input()
b=input()
if len(a)<len(b):
	a,b=b,a
if c=="+":
	if len(a)==len(b):
		l=list(a)
		l[0]='2'
		print(''.join(l))
	else:
		l=list(a)
		l[len(a)-len(b)]='1'
		print(''.join(l))
else:
	print(a+b[1:])