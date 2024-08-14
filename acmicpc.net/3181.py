l=['i', 'pa', 'te', 'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili']
k=list(map(str,input().split()))
print(str(k[0][0]).upper(), end='')
for i in range(1, len(k)):
    if not k[i] in l:
        print(str(k[i][0]).upper(), end='')
print()