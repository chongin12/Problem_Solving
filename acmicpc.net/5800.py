n=int(input())
for i in range(n):
    l=list(map(int,input().split()))[1:]
    l.sort()
    t=0
    for j in range(1,len(l),1):
        t=max(t,l[j]-l[j-1])
    print(f"Class {i+1}\nMax {l[-1]}, Min {l[0]}, Largest gap {t}")