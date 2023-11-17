n=int(input())
r=0
for _ in range(n):
    a,b=map(int,input().split())
    r=max(a*b,r)
print(r)