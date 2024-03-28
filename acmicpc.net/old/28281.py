N,X=map(int,input().split())
l=list(map(int,input().split()))
r=987654321
for i in range(1, N, 1):
    r=min(r,l[i-1]+l[i])
print(r*X)