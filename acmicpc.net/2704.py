for _ in range(int(input())):
    a,b,c=map(lambda x:bin(int(x))[2:].zfill(6),map(str,input().split(':')))
    s=""
    for i in range(6):s+=a[i]+b[i]+c[i]
    print(s, a+b+c)