a,b=map(int,input().split())
if a==b:print((a-2)**2+1)
else:print(min(a-1,b-1)**2)