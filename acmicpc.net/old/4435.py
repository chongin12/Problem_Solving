for i in range(int(input())):
    l=list(map(int,input().split()))
    a=l[0]+2*l[1]+3*l[2]+3*l[3]+4*l[4]+10*l[5]
    l=list(map(int,input().split()))
    b=l[0]+2*l[1]+2*l[2]+2*l[3]+3*l[4]+5*l[5]+10*l[6]
    print(f"Battle {i+1}:", end=' ')
    if a==b:print("No victor on this battle field")
    elif a>b:print("Good triumphs over Evil")
    else:print("Evil eradicates all trace of Good")