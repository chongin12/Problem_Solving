n=int(input())
l=list(map(int,input().split()))
cnt=0
res=1
prev=0
for i in l:
    if prev<=i:
        cnt+=1
        res=max(res,cnt)
    else:
        cnt=1
    prev=i
prev=100001
cnt=0
for i in l:
    if prev>=i:
        cnt+=1
        res=max(res,cnt)
    else:
        cnt=1
    prev=i
print(res)