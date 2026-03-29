q=[]
n=int(input())
while True:
    a=int(input())
    if a==-1:break
    if a==0:
        q.pop(0)
        continue
    if len(q)==n:continue
    q.append(a)
if len(q)==0:print("empty")
else:
    for i in q:
        print(i, end=' ')
    print()