n=int(input())
a=[]
b=[]
for i in list(map(int,input().split())):
    a.append(i)
for i in list(map(int,input().split())):
    b.append(i)
res=0
A,B=0,0

for i in range(n):
    if a[i]==b[i]:
        if A<B:A,B=A+1,0
        else:A,B=0,B+1
    elif (a[i]+1)%3==b[i]%3:
        A,B=0,B+1
    else:A,B=A+1,0
    res=max({res, A, B})
print(res)