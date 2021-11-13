r=int(input())
while 1:
	i=input()
	if i=='=':break
	a=int(input())
	if i=="+":r+=a
	if i=='-':r-=a
	if i=='/':r//=a
	if i=='*':r*=a
print(r)