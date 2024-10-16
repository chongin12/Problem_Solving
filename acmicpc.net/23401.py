s = [0,0]
prev=-1
strick = 0
v=[]
for i in range(int(input())):
    t,ai,bi=map(int,input().split())
    for k in v:
        if k[0]+10>=t and k[1]==ai:
            if ai<=4:s[0]+=50
            else:s[1]+=50
            break
    if ai<=4:s[0]+=100
    else:s[1]+=100
    v.append([t,ai,bi])
    
print(s[0], s[1])