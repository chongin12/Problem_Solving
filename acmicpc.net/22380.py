while True:
    n,m=map(int,input().split())
    if n==0:break
    m//=n
    r=0
    for i in list(map(int,input().split())):
        r+=min(m,i)
    print(r)