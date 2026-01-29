n,m=map(int,input().split())
s=set()
for _ in range(m):
    i,j,k=map(int,input().split())
    s.add((i,j,k))
res=0
for i in s:
    a,b,c=i
    if (a+1,b,c) in s and (a-1,b,c) in s and (a,b+1,c) in s and (a,b-1,c) in s and (a,b,c+1) in s and (a,b,c-1) in s:res+=1
print(res)