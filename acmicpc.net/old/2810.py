l=[0] * 52
n=int(input())
a=input()
r=0
for i in a:
    if i=='L':r+=1
if r>=4:n-=r//2-1
print(n)