n=int(input())
r=0.0
l=list(map(float,input().split()))
for i in l:
    r+=(i**3)
print(f"{r**(1/3.0):.6f}")