a=int(input())
r=0
while a!=1:
    if a%2==0:
        a/=2
    else:
        a=a*3+1
    r+=1
print(r)