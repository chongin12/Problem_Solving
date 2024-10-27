l,h=1,10
while True:
    n=int(input())
    if n==0:break
    s=input()
    if s=="too high":h=min(h,n-1)
    elif s=="too low":l=max(l,n+1)
    else:
        if h<n or l>n:print("Stan is dishonest")
        else:print("Stan may be honest")
        l,h=1,10