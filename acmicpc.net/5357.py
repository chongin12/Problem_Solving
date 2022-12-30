n=int(input())
for i in range(n):
    a=input()
    for j in range(len(a)):
        if j==0:
            print(a[j],end='')
            continue
        if a[j]!=a[j-1]:print(a[j],end='')
    print()