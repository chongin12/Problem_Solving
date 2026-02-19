for i in range(int(input())):
    l=list(map(int,input().split()))
    l.sort()
    if l[3]-l[1]>=4:print("KIN")
    else:print(l[1]+l[2]+l[3])
