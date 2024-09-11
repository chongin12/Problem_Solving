n,x=map(int,input().split())
l=list(map(int,input().split()))
idx=0
while True:
    if l[idx]<x:
        print(idx+1)
        break
    x+=1
    idx=(idx+1)%n
