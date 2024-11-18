n=int(input())
for i in range(n*5):
    for j in range(n*5):
        if i<n or j<n:print("@", end='')
    print()