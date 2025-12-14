import math
n=int(input())
if n<=3:print(n)
else:
    r=math.log2(n)
    if 2**int(r)==n:print(int(r)+1)
    else:print(int(r)+2)