l=[]
l.append(input())
l.append(input())
l.append(input())
l.append(input())
l.append(input())
l.append(input())
r=0
for i in l:
    if i=="W":r+=1
if r>=5:print(1)
elif r>=3:print(2)
elif r>=1:print(3)
else:print(-1)