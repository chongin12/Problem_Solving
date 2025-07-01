while True:
    try:
        s=input()
        a,b,c,d=0,0,0,0
        for i in s:
            k=ord(i)
            if i==' ':d+=1
            elif k>=ord('0') and k<=ord('9'):c+=1
            elif k>=ord('a') and k<=ord('z'):a+=1
            else:b+=1
        print(a,b,c,d)
    except:
        break