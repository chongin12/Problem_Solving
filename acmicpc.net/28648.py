T=int(input())
c=201
for _ in range(T):
    a,b=map(int,input().split())
    c=min(c,a+b)
print(c)