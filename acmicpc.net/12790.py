for i in range(int(input())):
    a,b,c,d,A,B,C,D=map(int,input().split())
    HP=max(1,A+a)
    MP=max(1,B+b)
    w=max(0,C+c)
    p=D+d
    r = 1 * (HP) + 5 * (MP) + 2 * (w) + 2 * (p)
    print(r)