a=input()[::-1]
r=""
t=""
for i in a:
    t=i+t
    if len(t)==3:
        r+=str(int(t, 2))
        t=""
if len(t)!=0:r+=str(int(t, 2))
print(int(r[::-1]))