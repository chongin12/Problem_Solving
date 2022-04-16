a,b,c=map(int,input().split())
r=0
if (b-a)%c>0:r=1
print(r+(b-a)//c)