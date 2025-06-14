n,l,w,h=map(int,input().split())
l*=1e9
w*=1e9
h*=1e9

lo,hi=1,2e18+1
cnt=0
while lo<hi-1:
    cnt+=1
    if cnt>10000:break
    mid=(lo+hi)//2
    if n>(l//mid)*(w//mid)*(h//mid):
        hi=mid
    else:lo=mid
print(f"{lo/1e9:.9f}")