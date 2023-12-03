import math
n=int(input())
for _ in range(n):
    a=input()
    k=int(math.sqrt(len(a)))
    r=''
    for i in range(k):
        for j in range(k):
            r+=a[(k-j-1)*k+i]
    print(r[::-1])
