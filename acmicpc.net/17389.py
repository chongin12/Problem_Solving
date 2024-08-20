n=int(input())
r,a,c=0,0,0
for i in input():
    a+=1
    if i=='O':
        r+=a+c
        c+=1
    else:
        c=0
print(r)