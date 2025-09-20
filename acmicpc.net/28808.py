a,b=map(int,input().split())
r=0
for i in range(a):
    if input().count("+")>0:
        r+=1
print(r)