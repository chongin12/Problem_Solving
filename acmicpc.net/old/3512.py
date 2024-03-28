
a,b=map(int,input().split())
bed=0
balco=0
total=0
for i in range(a):
    c,d=map(str,input().split())
    e=int(c)
    if d=="bedroom":bed+=e
    elif d=="balcony":balco+=e
    total+=e
print(total)
print(bed)
print(b*(total-balco/2))
