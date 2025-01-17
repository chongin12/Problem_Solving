while True:
    try:
        n=int(input())
        s = set([])
        cnt=0
        for i in range(1,111):
            cnt+=1
            a=n*i
            while a>0:
                s.add(a%10)
                a//=10
            if len(s)==10:break
        print(cnt)
    except:
        break