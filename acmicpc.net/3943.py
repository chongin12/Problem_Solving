import sys
input=sys.stdin.readline
t=int(input())
for i in range(t):
    n=int(input())
    r=n
    for j in range(1000):
        if n==1:break
        if n%2==1:n=n*3+1
        else:n=n//2
        r=max(r,n)
    print(r)