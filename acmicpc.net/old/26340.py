for _ in range(int(input())):
    k=input()
    print("Data set:",k)
    a,b,c=map(int,k.split())
    for _ in range(c):
        if a>b:a//=2
        else:b//=2
    print(f"{max(a,b)} {min(a,b)}\n")