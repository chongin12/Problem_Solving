for i in range(int(input())):
    a=input()
    r=0
    for j in a:
        if j==' ':continue
        r+=ord(j)-64
    if r==100:print("PERFECT LIFE")
    else:print(r)