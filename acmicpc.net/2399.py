n=int(input())
l=list(map(int,input().split()))
r=0
for i in range(n):
    for j in range(n):
        r+=abs(l[i]-l[j])
print(r)