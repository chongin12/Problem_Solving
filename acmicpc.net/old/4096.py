def isPelin(k: str) -> bool:
    for i in range(len(k)//2):
        if k[i]!=k[-(i+1)]: return False
    return True

while True:
    a=input()
    if a=="0":break
    cnt=0
    while True:
        if isPelin(a):break
        l=len(a)
        b=int(a)+1
        c=str(b)
        r=""
        r = ''.join(["0" for i in range(l-len(c))])
        r = r+c
        cnt+=1
        a=r
    print(cnt)