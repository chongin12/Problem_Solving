n=int(input())
for _ in range(n):
    k=input()
    print(k)
    l=list(map(int,k.split()))
    if l.count(17)==1 and l.count(18)==1:print("both")
    elif l.count(17)==1:print("zack")
    elif l.count(18)==1:print("mack")
    else:print("none")
    print()