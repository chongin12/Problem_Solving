for i in range(int(input())):
    a,b=map(str,input().split())
    print(bin(int(a,2)+int(b,2))[2:])