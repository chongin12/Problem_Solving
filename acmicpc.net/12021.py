a,b=map(float,input().split())
while True:
    ta=(a+b)/2
    tb=2*a*b/(a+b)
    if ta==a and tb==b:break
    a,b=ta,tb
print(f"{a:.6f} {b:.6f}")