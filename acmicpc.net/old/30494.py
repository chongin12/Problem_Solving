n=int(input())
A=19876543210
B=-A
for i in range(n):
    a,b=map(int,input().split())
    A=min(b,A)
    B=max(b,B)
print(B-A)