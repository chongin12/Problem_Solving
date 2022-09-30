a,b,c=map(int,input().split())
d=0
if a==1:d+=1
if b==1:d+=1
if c==1:d+=1
print(1 if d>1 else 2)