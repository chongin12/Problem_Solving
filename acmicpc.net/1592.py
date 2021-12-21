n,m,L=map(int,input().split())
l=[0 for i in range(51)]
now=0
cnt=0
while 1:
	l[now]+=1
	if l[now]==m:break
	if l[now]%2==0:now-=L
	else:now+=L
	cnt+=1
	now=(now+n)%n
print(cnt)