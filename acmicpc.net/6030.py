a,b=map(int,input().split())
for i in range(a):
    for j in range(b):
        if a%(i+1)==0 and b%(j+1)==0:print(i+1,j+1)