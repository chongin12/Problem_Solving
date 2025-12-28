r,c=map(int,input().split())
a=[]
for i in range(r):
    a.append(input())
A,B=map(int,input().split())
for i in range(r):
    a[i]+=a[i][::-1]
for i in range(r):
    a.append(a[r-i-1])
l=list(a[A-1])
if a[A-1][B-1]=='.':
    l[B-1]='#'
else:
    l[B-1]='.'
a[A-1]=''.join(l)

for i in range(r*2):
    print(a[i])