T=int(input())
for _ in range(T):
    n=int(input())
    if n==1:print("A")
    elif n==2:print("B")
    else:
        n-=3
        k=(n//3+2)%4
        p=n%3
        if p==1:p=-1
        else:p=0
        alp=(k+p+4)%4
        print(chr(65+alp))