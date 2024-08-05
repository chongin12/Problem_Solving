import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
par = [i for i in range(1000001)] # 각 노드의 부모가 누구인지
def Find(x): # x가 속한 그룹의 대표를 리턴.
    if par[x]==x:return x
    par[x]=Find(par[x])
    return par[x]

def Union(a, b):
    A = Find(a)
    B = Find(b)
    par[A] = B

V,E=map(int,input().split())
edges=[]
for i in range(E):
    a,b,c=map(int,input().split())
    edges.append([c,a,b])

edges.sort()
res=0

for edge in edges:
    w,u,v=edge
    if Find(u) == Find(v):
        continue
    Union(u, v)
    res+=w
print(res)