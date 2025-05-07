T=int(input())
for i in range(T):
    a1,a2,a3=map(float,input().split())
    b1,b2,b3=map(float,input().split())
    c1,c2,c3=map(float,input().split())

    if (b2*a1-a2*b1) == 0 or (c2*b1-b2*c1) == 0 or (a2*c1-c2*a1) ==0:
        print("0.0000")
        continue
    

    x1=(a2*b3-b2*a3)/(b2*a1-a2*b1)
    if a2==0:
        if b2==0:
            print("0.0000")
            continue
        else:
            y1=(-b1*x1-b3)/b2
    else:
        y1=(-a1*x1-a3)/a2
        
    
    
    x2=(b2*c3-c2*b3)/(c2*b1-b2*c1)
    if b2==0:
        if c2==0:
            print("0.0000")
            continue
        else:
            y2=(-c1*x2-c3)/c2
    else:
        y2=(-b1*x2-b3)/b2


    
    x3=(c2*a3-a2*c3)/(a2*c1-c2*a1)
    if c2==0:
        if a2==0:
            print("0.0000")
            continue
        else:
            y3=(-a1*x3-a3)/a2
    else:
        y3=(-c1*x3-c3)/c2

    res = abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3)*0.5
    print(f"{res:.4f}")