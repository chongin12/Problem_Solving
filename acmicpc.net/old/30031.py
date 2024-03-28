n=int(input())
r=0
for _ in range(n):
    a,b=map(int,input().split())
    b//=68
    if a==136:r+=b*1000
    if a==142:r+=b*5000
    if a==148:r+=b*10000
    if a==154:r+=b*50000
print(r)