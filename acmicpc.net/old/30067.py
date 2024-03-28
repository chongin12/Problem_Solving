l=[]
r=0
for i in range(10):
    l.append(int(input()))
    r+=l[-1]
for i in range(10):
    if r-l[i]==l[i]:
        print(l[i])
        break