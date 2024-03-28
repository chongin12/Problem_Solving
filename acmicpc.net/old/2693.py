t=int(input())
for _ in range(t):
    l=list(map(int,input().split()))
    l.sort()
    l.reverse()
    print(l[2])