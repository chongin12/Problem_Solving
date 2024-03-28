a=int(input())
for _ in range(a):
    b,c=map(str,input().split())
    for _ in range(int(b)):
        print(c,end='')
    print()