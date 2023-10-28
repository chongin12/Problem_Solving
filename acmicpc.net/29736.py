a,b=map(int,input().split())
k,x=map(int,input().split())
r=0
for i in range(a, b+1, 1):
    if abs(i-k)<=x:r+=1
if r==0:print("IMPOSSIBLE")
else:print(r)