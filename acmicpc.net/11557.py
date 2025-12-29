t=int(input())
for _ in range(t):
    n=int(input())
    a=[]
    for i in range(n):
        s,l=map(str,input().split())
        l=int(l)
        a.append([s,l])
    a.sort(key=lambda x : x[1])
    print(a[-1][0])
