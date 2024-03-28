n=int(input())
c=0
while True:
    if n//10==0:break
    k=n%10
    n//=10
    while n>0:
        k=k*(n%10)
        n//=10
    n=k
    c+=1
print(c)
    