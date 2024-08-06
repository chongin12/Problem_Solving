import math
c,k=map(int,input().split())
c=c/(10**k)
if c/1>=0.5:c=math.floor(c+0.5)
else:c=math.ceil(c-0.5)
c=c*(10**k)
print(c)