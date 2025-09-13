import math
for i in range(int(input())):
    n=int(input())
    if n==int(math.sqrt(n))**2:
        print(1)
    else:print(0)