s=set()
n=int(input())
res=0
for _ in range(n):
    a,b=map(int,input().split())
    if b==0:
        if a in s:
            s.remove(a)
        else:res+=1
    else:
        if not(a in s):
            s.add(a)
        else:res+=1
print(res+len(s))