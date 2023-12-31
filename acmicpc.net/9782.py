cnt=0
while True:
    cnt+=1
    l=list(map(int,input().split()))
    if l[0]==0:break
    n=l[0]
    l=l[1:]
    if n%2==1:
        print(f"Case {cnt}: {l[(n+1)//2-1]:.1f}")
    else:
        print(f"Case {cnt}: {(l[(n+1)//2-1]+l[(n+1)//2])/2:.1f}")


    