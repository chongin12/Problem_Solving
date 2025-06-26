n=int(input())
for i in range(n):
    s=sorted(input().lower())
    r=""
    for j in range(26):
        a=chr(j+97)
        if a not in s:r+=a
    if r=="":print("pangram")
    else:print(f"missing {r}")