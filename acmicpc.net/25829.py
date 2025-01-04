n=int(input())
a,ea,b,eb=0,0,0,0
for _ in range(n):
    e,v1,v2=map(int,input().split())
    a+=v1
    b+=v2
    if v1>v2:ea+=e
    else:eb+=e
if a>b and ea>eb:print("1")
elif a<b and ea<eb:print("2")
else:print("0")