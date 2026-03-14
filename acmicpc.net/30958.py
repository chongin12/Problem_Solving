n=int(input())
a=input()
r=0
for i in range(26):
    r=max(r,a.count(chr(97+i)))
print(r)