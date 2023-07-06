k=list(map(int,input().split(":")))
a=3600*k[0]+60*k[1]+k[2]

k=list(map(int,input().split(":")))
b=3600*k[0]+60*k[1]+k[2]
print(b-a if b>a else b-a+86400)