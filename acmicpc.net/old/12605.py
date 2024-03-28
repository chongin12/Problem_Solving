a=int(input())
for i in range(a):
    print(f"Case #{i+1}:", end='')
    l=list(map(str,input().split()))
    for s in list(reversed(l)):
        print(f" {s}", end='')
    print()