n=int(input())
e=0
for i in input():
    if int(i)%2==0:e+=1
    else:e-=1
if e==0:print("-1")
elif e>0:print("0")
else:print("1")