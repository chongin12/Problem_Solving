a,b=map(int,input().split())
c,d=map(int,input().split())
n=int(input())
r=0
for i in range(a*60+b, c*60+d+1):
	if i%10==n or i%60//10==n or i//60%10==n or i//60//10==n:
		r+=1
print(r)