n,k=map(int,input().split())
cnt=0
a=[0 for i in range(20)]
for i in range(n):
    s,y=map(int,input().split())
    a[s+y*2]+=1
for i in a:
    if i%k!=0:cnt+=1
    cnt+=i//k
print(cnt)