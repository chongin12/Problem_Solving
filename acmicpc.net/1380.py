s=0
while 1:
    s+=1
    n=int(input())
    if n==0:break
    l=[]
    r=[0 for i in range(n)]
    for i in range(n):
        l.append(input())
    for i in range(2*n-1):
        a,b=input().split()
        r[int(a)-1]+=1
    for i in range(n):
        if r[i]==1:
            print(s,l[i])
            break