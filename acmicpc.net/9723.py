T=int(input())
for i in range(T):
    print(f"Case #{i+1}: ", end='')
    l=sorted(list(map(int,input().split())))

    if l[2]**2==l[1]**2+l[0]**2:
        print("YES")
    else:
        print("NO")

