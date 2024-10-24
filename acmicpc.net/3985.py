l=int(input())
n=int(input())
v=[0 for i in range(1001)]
r1=[0,0]
r2=[0,0]
for i in range(n):
    p,k=map(int,input().split())
    if r1[0]<k-p+1:r1=[k-p+1,i+1]
    cnt=0
    for j in range(k-p+1):
        if v[p+j]==0:cnt+=1
        v[p+j]=1
    if r2[0]<cnt:r2=[cnt,i+1]
print(r1[1])
print(r2[1])