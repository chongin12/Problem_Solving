a,b=map(str,input().split())
c,d=-1,0
l=[[]]
for i in range(len(b)):
    l.append([])
    for j in range(len(a)):
        l[i].append('.')
for i in range(len(a)):
    for j in range(len(b)):
        if a[i]==b[j]:
            c,d=j,i
            break
    if c!=-1:break
for i in range(len(a)):
    l[c][i]=a[i]
for i in range(len(b)):
    l[i][d]=b[i]
for i in range(len(b)):
    for j in range(len(a)):
        print(l[i][j], end='')
    print()
