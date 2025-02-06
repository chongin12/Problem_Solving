T,X=map(int,input().split())
N=int(input())
for i in range(N):
    k=int(input())
    l=list(map(int,input().split()))
    if not (X in l):
        print("NO")
        exit(0)

print("YES")