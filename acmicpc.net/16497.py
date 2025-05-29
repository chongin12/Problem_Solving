n=int(input())
v=[0 for i in range(32)]
for _ in range(n):
    a,b=map(int,input().split())
    for i in range(a,b):v[i]+=1
k=int(input())
for i in range(32):
    if v[i]>k:
        print(0)
        exit()
print(1)