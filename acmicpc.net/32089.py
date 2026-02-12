while True:
    n=int(input())
    if n==0:break
    l=list(map(int,input().split()))
    m=0
    for i in range(2,len(l)):
        m=max(m,l[i]+l[i-1]+l[i-2])
    print(m)
