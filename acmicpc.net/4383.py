while True:
    try:
        s=set([])
        f=True
        l=list(map(int,input().split()))
        n=l[0]
        for i in range(2, n+1, 1):
            if abs(l[i]-l[i-1])<=0 or abs(l[i]-l[i-1])>=n:
                f=False
                break
            if abs(l[i]-l[i-1]) in s:
                f=False
                break
            s.add(abs(l[i]-l[i-1]))
        if f:print("Jolly")
        else:print("Not jolly")
    except:
        break