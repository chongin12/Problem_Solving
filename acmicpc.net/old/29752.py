n=int(input())
t=0
r=0
for i in list(map(int,input().split())):
    if i>0:t+=1
    else:t=0
    r=max(t,r)
print(r)