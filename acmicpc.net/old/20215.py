import math
a,b=map(int,input().split())
print(f"{a+b-math.sqrt(a*a+b*b):.8f}")