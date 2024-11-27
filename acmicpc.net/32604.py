flag=True
prev=[0,0]
for _ in range(int(input())):
    a,b=map(int,input().split())
    if prev[0]<=a and prev[1]<=b:
        prev=[a,b]
    else:
        flag=False
        break

if flag:print("yes")
else:print("no")