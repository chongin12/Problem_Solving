l=sorted(list(map(int,input().split())))
r=0
for i in range(4):
    if l[i]>=l[4]-1000:r+=1
print(r)