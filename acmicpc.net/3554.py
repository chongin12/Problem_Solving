n=int(input())
l=list(map(int,input().split()))
for _ in range(int(input())):
    a,b,c=map(int,input().split())
    if a==1:
        for i in range(b-1, c):
            l[i]=l[i]*l[i]%2010
    else:
        print(sum(l[b-1:c]))
    