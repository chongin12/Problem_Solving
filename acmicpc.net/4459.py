n=int(input())
a=[]
for i in range(n):
    a.append(input())
k=int(input())
for i in range(k):
    w=int(input())
    if w<1 or w>n:
        print(f"Rule {w}: No such rule")
    else:
        print(f"Rule {w}: {a[w-1]}")
