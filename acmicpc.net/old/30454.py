N,L=map(int,input().split())
p=''
x,y=0,0
for _ in range(N):
    a=input()
    c=0
    p='0'
    for i in a:
        if p=='0' and i=='1':c+=1
        p=i
    if c>x:x,y=c,1
    elif c==x:y+=1
print(x, y)

