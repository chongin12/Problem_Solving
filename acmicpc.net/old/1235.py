k=int(input())
l=[]
for i in range(k):
    l.append(input()[::-1])
for i in range(1, len(l[0]), 1):
    s=set([])
    for j in l:
        s.add(j[:i])
    if len(s)==len(l):
        print(i)
        exit()
print(len(l[0]))