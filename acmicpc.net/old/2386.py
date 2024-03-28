while True:
    a=input()
    if a=="#":break
    print(a[0], a.count(a[0].upper())+a.count(a[0].lower())-1)