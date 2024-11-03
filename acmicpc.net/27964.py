n=int(input())
d=set()
for i in map(str,input().split()):
    if len(i)>=6 and i[-6:]=="Cheese":
        d.add(i)
if len(d)>=4:print("yummy")
else:print("sad")