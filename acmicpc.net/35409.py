l=[
    [390,540],
    [590,600],
    [650,660],
    [710,720],
    [770,830],
    [880,890],
    [940,950],
    [1000,1370]
]

h,m=map(int,input().split())
d=h*60+m
k=False
for i in l:
    if d>=i[0] and d<=i[1]:
        k=True
if k==True:print("Yes")
else:print("No")