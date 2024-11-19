n=int(input())
for i in range(n):
    s=input()
    r=0
    for j in range(len(s)//8):
        substr = s[8*j:8*(j+1)]
        if substr[0:7].count("1") % 2 != int(substr[7]): r+=1
    print(r)