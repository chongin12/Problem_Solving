n,k=map(int,input().split())
s=""
r=0
for i in range(1,n+1):
	if i%10!=k%10 and i%10!=(2*k)%10:
		r+=1
		s+=str(i)+" "
print(r)
if s!="":print(s)