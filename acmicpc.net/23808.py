n=int(input())
for i in range(5):
    for j in range(n):
        if i==0 or i==1 or i==3:
            for k in range(n):
                print("@", end='')
            for k in range(3*n):
                print(" ", end='')
            for k in range(n):
                print("@", end='')
        else:
            for k in range(5*n):
                print("@", end='')
        print()