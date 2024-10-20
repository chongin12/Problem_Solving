n=int(input())
for i in range(n):
    s1,s2=input(),input()
    r=0
    for j in range(26):
        r+=abs(s1.count(chr(97+j))-s2.count(chr(97+j)))
    print(f"Case #{i+1}: {r}")