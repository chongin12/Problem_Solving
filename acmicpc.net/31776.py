n=int(input())
res=0
for i in range(n):
    a,b,c=map(int,input().split())
    if a==-1:continue
    elif a<=b and b<=c:res+=1
    elif a<=b and c==-1:res+=1
    elif b==-1 and c==-1:res+=1
print(res)