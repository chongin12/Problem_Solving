n=int(input())
l=[]
for i in range(n):
    l.append(int(input()))
l.sort(reverse=True)
r=0
for i in range(n):
    r+=max(0,l[i]-i)
print(r)