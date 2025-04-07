for _ in range(int(input())):
    n=int(input())
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    cnt=0
    for i in l1:
        if i+500 in l1 and i+1000 in l2 and i+1500 in l2:
            cnt+=1
    print(cnt)