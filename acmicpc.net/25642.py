a,b=map(int,input().split())
while True:
    a,b=a,a+b
    if b>4:
        print("yt")
        break
    else:
        a,b=a+b,b
        if a>4:
            print("yj")
            break

