A,C,E=map(int,input().split())
a,b,c=map(int,input().split())
k=""
if c>=E:
    k="E"
    if b>=C/2:k="D"
    if b>=C:
        k="C"
        if a>=A/2:k="B"
        if a>=A:k="A"
print(k)