n=int(input())
for _ in range(n):
    a=int(input())
    for i in range(a//5):print("++++ ",end='')
    for i in range(a%5):print("|",end='')
    print()