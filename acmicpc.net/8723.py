a,b,c=map(int,input().split())
if a<c:a,c=c,a
if a<b:a,b=b,a
if a==b and b==c:print(2)
elif a*a==b*b+c*c:print(1)
else:print(0)