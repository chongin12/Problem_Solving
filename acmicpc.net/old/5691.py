while True:
    a,b=map(int,input().split())
    if a==0 and b==0:break
    r=min(2*a-b, 2*b-a)
    if (a+b)%2==0:r=min(r,(a+b)/2)
    print(r)