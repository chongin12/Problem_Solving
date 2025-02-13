while True:
    a=input()
    if a=="0":break
    p=''
    for i in list(map(int,a.split()))[1:]:
        if i==p:continue
        p=i
        print(i, end=' ')
    print("$")