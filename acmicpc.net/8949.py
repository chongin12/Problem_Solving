a,b=map(int,input().split())
res=""
while a!=0 or b!=0:
    res=str(a%10+b%10)+res
    a//=10
    b//=10
print(res)