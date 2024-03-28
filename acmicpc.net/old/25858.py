n,d=map(int,input().split())
l=[]
s=0
for j in range(n):
    a=int(input())
    l.append(a)
    s+=a
for j in range(n):
    print(d//s*l[j])