while True:
    try:
        m,p,l,e,r,s,n=map(int,input().split())
        for i in range(n):
            t=e*m
            m=p//s
            p=l//r
            l=t
        print(m)
    except:
        break