def f(a):
    ret=1
    for i in f"{a}":
        ret*=int(i)
    return ret

while True:
    n=int(input())
    if n==0:break
    print(n, end='')
    while n>9:
        n=f(n)
        print(f" {n}", end='')
    print()
    