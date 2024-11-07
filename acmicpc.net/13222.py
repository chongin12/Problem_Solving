import math
n,w,h=map(int,input().split())
for i in range(n):
    a=int(input())
    if a*a<=w*w+h*h:print("YES")
    else:print("NO")