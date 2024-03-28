n,m=map(int,input().split())
l=[]
for i in range(n):
    l.append(input())
input()
c=0
for i in range(n):
    k=input()
    for j in range(len(k)):
        if k[j]==l[i][j]:c+=1
print(c)