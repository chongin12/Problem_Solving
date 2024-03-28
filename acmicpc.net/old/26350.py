n=int(input())
for _ in range(n):
    a=list(map(int,input().split()))
    print("Denominations: ", end='')
    for i in a[1:]:
        print(i, end=' ')
    print()
    f=True
    for i in range(a[0]-1):
        if a[i+2]<a[i+1]*2:
            f=False
            break
    if f:print("Good coin denominations!\n")
    else:print("Bad coin denominations!\n")