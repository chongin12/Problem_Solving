h=int(input())
s=""
if h==0:
    print(1)
    exit(0)
elif h==1:
    print(0)
    exit(0)
if h%2==1:
    h-=1
    s="4"
while h>0:
    if h>=2:
        s=s+"8"
        h-=2
    else:
        s=s+"0"
        h-=1
print(s)