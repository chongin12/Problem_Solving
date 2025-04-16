a,b=map(int,input().split())
m=int(input())
l=list(map(int,input().split()))
r=0
t=1
for i in l[::-1]:
    r+=i*t
    t*=a

t=b
res=[]
while r>0:
    res.append(r%b)
    r//=b
print(*res[::-1])