m,d=map(int,input().split())
if d%m==0:
    print(d//m)
else:
    print(d//m+1)