for _ in range(int(input())):
    n,m,l=map(int,input().split())
    arr=list(map(int,input().split()))
    for i in arr:
        if i==-1:continue
        l=max(l,m-i)
    if l==1:
        print(f"The scoreboard has been frozen with 1 minute remaining.")
    else:
        print(f"The scoreboard has been frozen with {l} minutes remaining.")