l=list(map(int,input().split()))
a=[100,100,200,200,300,300,400,400,500]
r=0
for i in range(9):
	if l[i]>a[i]:r=9999
	r+=l[i]
if r>9998:print("hacker")
elif r>99:print("draw")
else:print("none")