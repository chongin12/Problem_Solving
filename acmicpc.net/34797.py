n=int(input())
r=0.0
r2=0.0
for i in range(n):
    s=input()
    r+=4-(ord(s[0])-65)
    if ord(s[0])<=67 and s[1]=='1':r2+=0.05
    elif ord(s[0])<=67 and s[1]=='2':r2+=0.025
print(f"{r/n+r2:.6f}")