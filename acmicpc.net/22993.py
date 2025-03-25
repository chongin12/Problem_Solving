n=int(input())
l=list(map(int,input().split()))
a=l[0]
l=l[1:]
l.sort()
flag=False
for i in l:
    if i<a:a+=i
    elif i>=a:
        flag=True
        break
if flag:print("No")
else:print("Yes")