w,b = 0,0
for _ in range(15):
    for i in list(map(str,input().split())):
        if i=='w':w+=1
        elif i=='b':b+=1
if w>0:print("chunbae")
elif b>0:print("nabi")
else:print("yeongcheol")