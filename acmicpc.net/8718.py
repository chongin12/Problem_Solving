a,b=map(int,input().split())
a=a*1000
b=b*1000
if a>=b*7:
    print(b*7)
elif a>=b*3+b//2:
    print(b*3+b//2)
elif a>=b+b//2+b//4:
    print(b+b//2+b//4)
else:
    print(0)