a,b=map(int,input().split())
r=a
if a>=b:print(0)
else:
    for i in range(2,a):
        r=(r*i)%b
    print(r)