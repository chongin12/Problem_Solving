N,M=map(int,input().split())
if N==0:print(1%M)
else:
    r=1
    for i in range(N):
        a=max(1,int(input()))
        r=r*a%M
    print(r)
