d=set()
s=input()
for i in range(1,len(s)):
    for j in range(len(s)-i+1):
        d.add(s[j:j+i])
print(len(d)+1)