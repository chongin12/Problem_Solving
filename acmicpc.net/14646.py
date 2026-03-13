n=int(input())
l=list(map(int,input().split()))
res=0
s=set()
for i in l:
    if i in s:
        s.remove(i)
    else:
        s.add(i)
    res=max(res,len(s))
print(res)