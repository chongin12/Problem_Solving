a=input()+input()[::-1]
a=a+a
b=a[::-1]
r=False
for i in range(4):
    if a[i:i+4]=="HEPC" or b[i:i+4]=="HEPC":r=True
if r:print("YES")
else:print("NO")