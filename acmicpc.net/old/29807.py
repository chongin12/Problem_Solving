input()
l=list(map(int,input().split()))+[0,0,0,0]
r=0
if l[0]>l[2]:r=(l[0]-l[2])*508
else:r=(l[2]-l[0])*108
if l[1]>l[3]:r+=(l[1]-l[3])*212
else:r+=(l[3]-l[1])*305
r+=l[4]*707
print(r*4763)
