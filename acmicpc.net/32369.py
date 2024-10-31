n,a,b=map(int,input().split())
r1,r2=1,1
for i in range(n):
    r1+=a
    r2+=b
    if r1<r2:
        r1,r2=r2,r1
    if r1==r2:
        r2-=1
print(r1,r2)