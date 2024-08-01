T=int(input())
for i in range(T):
    a=1
    n=int(input())
    for j in range(1,n+1,1):
        a*=j
        a%=10
    print(a)
