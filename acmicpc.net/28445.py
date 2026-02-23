a,b=map(str,input().split())
c,d=map(str,input().split())

l=list(set([a,b,c,d]))
l.sort()

for i in l:
    for j in l:
        print(i,j)