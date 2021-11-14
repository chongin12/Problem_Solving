n=int(input())
a=list(map(int,input().split()))
p=2
r=0
for i in a:
	if p==2 and i==0:
		r+=1
		p=0
	elif p==0 and i==1:
		r+=1
		p=1
	elif p==1 and i==2:
		r+=1
		p=2
print(r)