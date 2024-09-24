r=(0,'')
for _ in range(7):
    a,b=map(str,input().split())
    if r[0]<int(b):
        r=(int(b),a)
print(r[1])