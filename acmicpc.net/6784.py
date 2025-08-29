n=int(input())
a=[]
for i in range(n):
    a.append(input())
r=0
for i in range(n):
    if input()==a[i]:r+=1
print(r)