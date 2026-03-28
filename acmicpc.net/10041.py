w,h,n=map(int,input().split())
px,py=1,1
r=0
for i in range(n):
    x,y=map(int,input().split())
    if i==0:px,py=x,y
    if px<=x and py<=y:
        t=min(x-px, y-py)
        r+=x-px+y-py-t
    elif px>=x and py>=y:
        t=min(px-x, py-y)
        r+=px-x+py-y-t
    else:
        r+=abs(px-x)+abs(py-y)
    px,py=x,y
print(r)