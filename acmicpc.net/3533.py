l=[0]*10
r=0
cnt=0
for i in list(map(int,input().split())):
    l[cnt]=i
    cnt+=1
for i in range(10):
    for j in range(i+1, 10, 1):
        if l[i]==1 or l[j]==1:r^=1
for i in range(10):
    for j in range(i+1, 10, 1):
        for k in range(j+1, 10, 1):
            if l[i]==1 or l[j]==1 or l[k]==1:r^=1
print(r)