n=int(input())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
r=0
for i in range(len(l1)):
    if l1[i]>l2[i]:r+=3
    elif l1[i]==l2[i]:r+=1
print(r)