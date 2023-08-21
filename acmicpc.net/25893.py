from functools import reduce
n=int(input())
for _ in range(n):
    k=input()
    print(k)
    l=list(map(int,k.split()))
    r=reduce(lambda a, cur: a + (1 if cur>=10 else 0), l, 0)
    if r==0:print("zilch")
    elif r==1:print("double")
    elif r==2:print("double-double")
    else:print("triple-double")
    print()