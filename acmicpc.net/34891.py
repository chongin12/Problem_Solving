a,b=map(int,input().split())
r=0
if a%b==0:r=a//b
else:r=a//b+1
print(r)