import math
s=math.sqrt
H,V=map(float,input().split())
h,v=H*H,V*V
X=(H*s(h+v)-h)/V
a=s(h+X*X)
print(f"{a/2:.2f} {(X*s(h+v))/a:.2f}")