n=int(input())
s=""
i=0
while 9<=n:
	s=f"{n%9}"+s
	n//=9
if n!=0:
	s=f"{n%9}"+s
print(s)