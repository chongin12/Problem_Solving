t=int(input())
for i in range(t):
    x=int(input())
    a,b=0,1
    for i in range(x+1):
        a,b=b,a+b
    print(a)