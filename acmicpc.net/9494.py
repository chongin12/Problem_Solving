while True:
    n=int(input())
    if n==0:
        break
    idx = 0
    for _ in range(n):
        s=input()
        while idx<len(s) and s[idx]!=' ':
            idx+=1
    print(idx+1)