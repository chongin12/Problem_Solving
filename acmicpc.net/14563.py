t=int(input())
for i in list(map(int,input().split())):
    a=0
    for j in range(1,i):
        if i%j==0:a+=j
    if a==i:print("Perfect")
    elif a<i:print("Deficient")
    else:print("Abundant")