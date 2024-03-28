for i in range(3):
    a=input()
    r=1
    k=1
    for j in range(1,8):
        if a[j-1]==a[j]:
            k+=1
        else:
            r=max(r,k)
            k=1
    print(max(r,k))