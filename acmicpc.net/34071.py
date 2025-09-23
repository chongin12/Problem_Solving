n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
if a[0]==min(a):print("ez")
elif a[0]==max(a):print("hard")
else:print("?")