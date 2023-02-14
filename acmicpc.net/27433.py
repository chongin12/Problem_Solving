n=int(input())
if n==0:print(1)
else:
    r=1
    for i in range(n):
        r*=(i+1)
    print(r)