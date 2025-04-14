n,a,b=map(int,input().split())
for _ in range(8-n):
    X,Y=map(int,input().split())
    Y=min(6-X,Y)
    a+=X*3
    b+=Y*3+X*3
if a>=66 and b>=130:print("Nice")
else:print("Nae ga wae")