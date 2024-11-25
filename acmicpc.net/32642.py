input()
r=0
a=0
for i in list(map(int,input().split())):
    if i==0:a-=1
    else:a+=1
    r+=a
print(r)