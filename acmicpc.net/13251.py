M=int(input())
l=list(map(int,input().split()))
all=sum(l)
K=int(input())

r=0.0
for i in l:
    if i<K:continue
    a=1.0
    for j in range(K):
        a*=(i-j)/(all-j)
    r+=a

print(f"{r:.9f}")