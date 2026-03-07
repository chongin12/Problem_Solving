t=int(input())
for i in range(t):
    a=int(input())
    r=0
    while a>1:
        if a%2==1:
            r+=1
            a=a//2+1
        else:a//=2
    print(r)
