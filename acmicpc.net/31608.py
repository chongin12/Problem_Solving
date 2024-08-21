n=int(input())
a=input()
b=input()
r=0
for i in range(n):
    if a[i]!=b[i]:r+=1
print(r)