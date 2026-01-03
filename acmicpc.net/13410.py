n,k=map(int,input().split())
a=0
for i in range(k):
    a=max(a,int(str(n*(i+1))[::-1]))
print(a)