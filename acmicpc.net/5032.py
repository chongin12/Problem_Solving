e,f,c=map(int,input().split())
e+=f
r=0
while e>=c:
    r+=e//c
    e=e%c+e//c
print(r)