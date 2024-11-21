n=int(input())
r=0
for _ in range(3):
    if 7 in list(map(int,input().split())):r+=1
if r==3:print("777")
else:print("0")