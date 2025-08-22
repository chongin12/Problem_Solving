while True:
    a,b,c=map(int,input().split())
    if a==0:break
    r=0
    while a>=b+c+r:
        if b+r>a//2:
            break
        r+=1
    if a<b+c+r or b+r<=a//2:
        print("-1")
    else:print(r)