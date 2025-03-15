a1,a0=map(int,input().split())
c=int(input())
n0=int(input())
n=987654321
if a1*n0+a0 <= c*n0 and a1*n+a0 <= c*n:
    print("1")
else:print("0")