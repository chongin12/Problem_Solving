a,b=map(int,input().split())
c,d=map(int,input().split())
for i in range(0,1000000,1):
    if (i+a)%b==0 and (i+c)%d==0:
        print(i)
        break