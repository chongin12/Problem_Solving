r=0.0
for i in range(int(input())):
    a,b=map(float,input().split())
    r+=a*b
print(f"{r:.4f}")