N,C=map(int,input().split())
M=N
for i in range(C):
    a,b=map(int,input().split())
    if a>=N or b>=M:continue
    garoUp=a*M
    seroLeft=b*N
    k=max(garoUp, seroLeft)
    if garoUp==k:N,M=a,M
    else:N,M=N,b
print(N*M)