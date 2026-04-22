n=int(input())
w=int(input())
r=10*n
if n>=3:r+=20
if n==5:r+=50
if w>1000:r-=15
print(max(0,r))