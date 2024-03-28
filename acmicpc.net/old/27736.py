n=int(input())
L=list(map(int,input().split()))
l,r,m=0,0,0.0
for i in L:
    if i==0:m+=1.0
    elif i==1:l+=1
    else:r+=1
if m>=n/2:print("INVALID")
elif l<=r:print("REJECTED")
else:print("APPROVED")