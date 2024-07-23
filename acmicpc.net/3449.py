t=int(input())
for i in range(t):
    s=input()
    k=input()
    r=0
    for j in range(len(s)):
        if s[j]!=k[j]:r+=1
    print(f"Hamming distance is {r}.")