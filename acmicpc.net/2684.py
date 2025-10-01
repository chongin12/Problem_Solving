p=int(input())
for i in range(p):
    s=input()
    a=[0,0,0,0,0,0,0,0]
    for j in range(38):
        if s[j:j+3]=='TTT':a[0]+=1
        if s[j:j+3]=='TTH':a[1]+=1
        if s[j:j+3]=='THT':a[2]+=1
        if s[j:j+3]=='THH':a[3]+=1
        if s[j:j+3]=='HTT':a[4]+=1
        if s[j:j+3]=='HTH':a[5]+=1
        if s[j:j+3]=='HHT':a[6]+=1
        if s[j:j+3]=='HHH':a[7]+=1

    print(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7])