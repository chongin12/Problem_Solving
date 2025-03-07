for _ in range(int(input())):
    a,b=map(str,input().split())
    B=int(b)-1
    if (ord(a[0])-65+int(a[1])-1)%2 == (B%8+B//8)%2:
        print("YES")
    else:print("NO")