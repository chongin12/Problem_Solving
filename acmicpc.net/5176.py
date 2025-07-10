for _ in range(int(input())):
    p,m=map(int,input().split())
    a=[]
    for i in range(p):
        a.append(int(input()))
    print(p-len(set(a)))