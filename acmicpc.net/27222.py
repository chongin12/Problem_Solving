n=int(input())
l=list(map(int,input().split()))
r=0
for i in range(n):
    a,b=map(int,input().split())
    if l[i]==0:continue
    r+=max(0,b-a)
print(r)