n=int(input())
l=list(map(int,input().split()))
v=0.0
for i in l:
    v=1-(1-v)*(1-i/100)
    print(f"{v*100:.7f}")