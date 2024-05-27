n=int(input())
l=[]
for i in range(n):
    l.append(int(input()))
m=int(input())
r=0
for i in range(m):
    r+=l[int(input())-1]
print(r)