a,b,c=map(int,input().split())
r=0
m=-1
for i in range(int(input())*3):
	q,w,e=map(int,input().split())
	r+=a*q+b*w+c*e
	if i%3==2:
		m=max(m,r)
		r=0
print(m)