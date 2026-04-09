n=int(input())
l=list(map(int,input().split()))
freeze=1
t=0
while len(l)>0:
    r=0
    for i in range(len(l)):
        if l[i]>0:r+=1
        if i==0:continue
        if l[i]==0 and l[i-1]==0:break
    l=l[1:]
    t=max(t,r)
print(t)