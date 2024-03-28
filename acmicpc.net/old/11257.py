n=int(input())
for i in range(n):
    a,b,c,d=map(int,input().split())
    e=b+c+d
    if (e<55 or b<11) or (c<8 or d<12):
        print(f"{a} {e} FAIL")
    else:
        print(f"{a} {e} PASS")