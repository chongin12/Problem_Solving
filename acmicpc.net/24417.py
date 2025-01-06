n=int(input())
a,b=0,1
for i in range(n):
    a,b=b,a+b
    a%=1000000007
print(a, n-2)