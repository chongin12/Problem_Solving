a,b,c=map(int,input().split())
l=[0]*101
r=0
for _ in range(3):
    d,e=map(int,input().split())
    for i in range(d, e, 1):
        l[i]+=1
for i in range(101):
    if l[i]==1:r+=a
    elif l[i]==2:r+=b*2
    elif l[i]==3:r+=c*3
print(r)