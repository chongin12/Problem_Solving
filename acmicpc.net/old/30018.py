n=int(input())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
r=0
for i in range(n):
    r+=abs(l1[i]-l2[i])
print(r//2)