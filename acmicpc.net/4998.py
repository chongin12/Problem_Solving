while True:
    try:
        n,b,m=map(float,input().split())
        r=0
        while n<=m:
            r+=1
            n=n+n*(b/100)
        print(r)
    except:
        break