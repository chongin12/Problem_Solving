r,b=map(int,input().split())
l,w=0,0
for i in range(1,b+1):
    if b%i==0:
        a=i
        c=b//i
        if a*2+c*2+4==r:
            l,w=max(a+2,c+2),min(a+2,c+2)
            break
print(l, w)
