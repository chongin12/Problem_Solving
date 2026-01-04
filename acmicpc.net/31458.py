for _ in range(int(input())):
    s=input()
    cnt=0
    for i in s:
        if i!='!':break
        cnt+=1
    if len(s)==1:print(s)
    elif s[-1]=='!':
        cnt+=1
        print(cnt%2)
    else:
        cnt+=int(s[-1])
        print(cnt%2)