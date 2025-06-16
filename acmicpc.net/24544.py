n=int(input())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
print(sum(l1))
r=0
for i in range(len(l2)):
    if l2[i]==0:r+=l1[i]
print(r)