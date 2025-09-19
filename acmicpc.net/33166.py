p,q=map(int,input().split())
a,b=map(int,input().split())
print(a*min(p,q)+b*max(0,q-p))