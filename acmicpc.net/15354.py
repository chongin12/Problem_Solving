n=int(input())
p=''
r=0
for i in range(n):
    a=input()
    if p!=a:r+=1
    p=a
print(r+1)