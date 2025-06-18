n=int(input())
s=input()
s1=s[:n//2]
s2=s[n-n//2:][::-1]
set1=set()

for i in range(n//2):
    if s1[i] in set1:set1.remove(s1[i])
    else:set1.add(s1[i])
    if s2[i] in set1:set1.remove(s2[i])
    else:set1.add(s2[i])

if len(set1)!=0:print("No")
else:print("Yes")