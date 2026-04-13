n=int(input())
t=0
k=0
l=[]
for i in range(n+1):
    a,b=map(str,input().split())
    h,m=map(int,a.split(':'))
    v=h*60+m
    if b=="teacher":t=v
    else:l.append(v)
r=0
h,m=map(int,input().split(':'))
k=h*60+m
for i in l:
    if i>=k and i>=t:r+=1
print(r)