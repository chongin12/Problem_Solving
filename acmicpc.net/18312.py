n,k=map(int,input().split())
h,m,s=0,0,0
r=0
while True:
    if h==n+1:break
    if h//10==k or h%10==k or m//10==k or m%10==k or s//10==k or s%10==k:r+=1
    s+=1
    if s==60:
        m+=1
        s=0
    if m==60:
        h+=1
        m=0

print(r)