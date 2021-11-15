import math
a,b=map(int,input().split())
c=int(-a+math.sqrt(a**2-b))
d=int(-a-math.sqrt(a**2-b))
if c==d:print(c)
else:print(min(c,d),max(c,d))