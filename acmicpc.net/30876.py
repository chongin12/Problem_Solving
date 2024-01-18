n=int(input())
r=[0,99999]
for _ in range(n):
    a,b=map(int,input().split())
    if r[1]>b:r=[a,b]
print(r[0], r[1])