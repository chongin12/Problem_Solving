import datetime as dt
while True:
    d,m,y=map(int,input().split())
    if y==0:break
    x=dt.datetime(y,m,d)
    a=dt.datetime(y,1,1)
    print((x-a).days+1)

