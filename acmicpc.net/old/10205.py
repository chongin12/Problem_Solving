t=int(input())
for i in range(t):
    n=int(input())
    for j in input():
        if j=='c':
            n+=1
        else:
            n-=1
    print(f"Data Set {i+1}:")
    print(n)
    print()