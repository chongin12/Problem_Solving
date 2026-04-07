while True:
    a,b,c,d=map(int,input().split())
    if a==0 and b==0:break
    if a==0:a=d//c//b
    elif b==0:b=d//c//a
    elif d==0:d=a*b*c
    else:c=d//a//b
    print(a,b,c,d)