import math
for _ in range(int(input())):
    l=list(map(float,input().split()))
    r1,r2=0,0
    for i in range(3):
        a=l[i*2]
        b=l[i*2+1]
        c=math.sqrt(a*a+b*b)
        if c<=3:r1+=100
        elif c<=6:r1+=80
        elif c<=9:r1+=60
        elif c<=12:r1+=40
        elif c<=15:r1+=20
    for i in range(3):
        a=l[6+i*2]
        b=l[6+i*2+1]
        c=math.sqrt(a*a+b*b)
        if c<=3:r2+=100
        elif c<=6:r2+=80
        elif c<=9:r2+=60
        elif c<=12:r2+=40
        elif c<=15:r2+=20
    res="TIE"
    if r1>r2:res="PLAYER 1 WINS"
    if r1<r2:res="PLAYER 2 WINS"
    print(f"SCORE: {r1} to {r2}, {res}.")