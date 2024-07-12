a,b=map(int,input().split())
x,y=0,0
for i in range(a):
    for j in input():
        if j=='0':x+=1
        else:y+=1
print(min(x,y))