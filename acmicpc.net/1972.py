while True:
    s=input()
    if s=='*':break
    N=len(s)
    flag=True
    for i in range(N-1): # i-쌍
        nums=set()
        for j in range(N):
            if j+i+1>=N:break
            temp=""+s[j]+s[j+i+1]
            if temp in nums:flag=False
            nums.add(temp)
    if flag:
        print(f"{s} is surprising.")
    else:
        print(f"{s} is NOT surprising.")
