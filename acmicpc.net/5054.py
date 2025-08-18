t=int(input())
for _ in range(t):
    n=input()
    l=list(map(int, input().split()))
    print(2*(max(l)-min(l)))