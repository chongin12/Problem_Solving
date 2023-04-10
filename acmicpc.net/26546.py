n=int(input())
for i in range(n):
    a=input().split()
    b=int(a[1])
    c=int(a[2])
    for j in range(len(a[0])):
        if b<=j and j<c:continue
        print(a[0][j], end='')
    print()