l=list(map(int,input().split()))
n=int(input())
r=0
for i in range(n):
    a,b,c=map(str,input().split())
    if float(b)>=2.0 and int(c)>=17:
        r+=l[int(a)]
print(r)
