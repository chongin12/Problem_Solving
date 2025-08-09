while True:
    s=input()
    if s=="#":break
    r=0
    for i in range(len(s)):
        if s[i]==' ':continue
        r+=(i+1)*(ord(s[i])-64)
    print(r)
