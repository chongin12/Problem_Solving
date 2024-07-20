n=int(input())
s=input()
a,b,c=[],[],[]
for i in range(17):
    a.append('A')
    a.append('B')
    a.append('C')
    a.append('A')
    a.append('B')
    a.append('C')
    b.append('B')
    b.append('A')
    b.append('B')
    b.append('C')
    b.append('B')
    b.append('A')
    b.append('B')
    b.append('C')
    c.append('C')
    c.append('C')
    c.append('A')
    c.append('A')
    c.append('B')
    c.append('B')

A,B,C=0,0,0
for i in range(n):
    if s[i]==a[i]:A+=1
    if s[i]==b[i]:B+=1
    if s[i]==c[i]:C+=1

m=max(A,B,C)
print(m)
if m==A:print("Adrian")
if m==B:print("Bruno")
if m==C:print("Goran")