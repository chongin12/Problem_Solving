a=int(input())
for i in range(a):
    l=list(map(int,input().split()))
    b=0
    c=0
    for j in l[1:]:
        if j%2==0:b+=j
        else:c+=j
    if b==c:print("TIE")
    elif b>c:print("EVEN")
    else:print("ODD")