while 1:
    a=int(input())
    if a==0:break
    l=list(map(int,input().split()))
    c=0
    for i in l:
        if i>0:c+=1
    print(f"Mary won {a-c} times and John won {c} times")