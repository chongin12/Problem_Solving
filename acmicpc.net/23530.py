n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    r=1 if a+b!=1 else 2
    print(r)