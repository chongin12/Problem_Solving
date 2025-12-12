import math
n=int(input())
cnt=0
for i in range(n):
    a=input()
    if int(a)>=100:cnt+=int(a)
    else:
        a=a.replace('0','9')
        a=a.replace('6','9')
        cnt+=int(a)

print(math.ceil(cnt/n-0.4999999999))