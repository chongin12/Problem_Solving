s=0
n,k=map(int,input().split())
r=0
for i in range(n):
    a=input()
    if a=="save":
        s=r
    elif a=="load":
        r=s
    elif a=="shoot":
        r-=1
    else:
        r+=k
    print(r)