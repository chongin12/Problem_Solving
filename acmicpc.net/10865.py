d=dict()
n,m=map(int,input().split())
for i in range(n):
    d[i+1]=0
for i in range(m):
    u,v=map(int,input().split())
    d[u]+=1
    d[v]+=1

for i in range(n):
    print(d[i+1])