n,k=map(int,input().split())
for i in range(k):
    s,t,r=map(int,input().split())
    a,b,v=0,0,0
    while a<n:
        if b==t:
            b=0
            v+=r
        b+=1
        v+=1
        a+=s
    print(v)