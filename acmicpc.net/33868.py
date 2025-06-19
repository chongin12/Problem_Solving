n=int(input())
l1,l2=[],[]
for i in range(n):
    a,b=map(int,input().split())
    l1.append(a)
    l2.append(b)
print(max(l1)*min(l2)%7+1)
