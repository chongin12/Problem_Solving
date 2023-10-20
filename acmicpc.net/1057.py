a,b,c=map(int,input().split())
r=0
b-=1
c-=1
while b!=c:
    b//=2
    c//=2
    r+=1

print(r)