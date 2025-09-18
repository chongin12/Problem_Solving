n=int(input())
for i in range(n):
    l=list(map(int,input().split()))
    k=l[0]
    l=l[1:]
    r=[0 for i in range(10)]
    for j in range(k):
        r[l[j*2+1]]+=1
    print(max(r))
