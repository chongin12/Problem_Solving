n,m=map(int,input().split())
xmin, xminIdx = 999,0
ymin, yminIdx = 999,0
for i in range(n-1):
    a=int(input())
    if xmin>a:
        xmin=a
        xminIdx=i+1
l=list(map(int,input().split()))

if xmin>l[0]:
    xmin=l[0]
    xminIdx=n

for i in range(m):
    if ymin>l[i]:
        ymin=l[i]
        yminIdx=i+1

print(xminIdx, yminIdx)