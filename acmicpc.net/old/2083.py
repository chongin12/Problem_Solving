while 1:
    a,b,c=input().split()
    if a=="#":break
    if int(b)>17 or int(c)>=80:print(a, "Senior")
    else:print(a, "Junior")