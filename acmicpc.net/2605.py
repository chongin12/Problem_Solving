n=int(input())
l=list(map(int,input().split()))
r=[1]
for i in range(1,n,1):
    r.insert(i-l[i], i+1)
for i in r:
    print(i, end=' ')