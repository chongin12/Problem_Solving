n,m=map(int,input().split())
l=[[0]*m for i in range(n)]
for t in range(2):
    for i in range(n):
        a=list(map(int,input().split()))
        for j in range(m):
            l[i][j]+=a[j]
for i in l:
    for j in i:
        print(j, end=' ')
    print()