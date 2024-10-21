n=int(input())
s=[]
def f(s1,s2):
    k=0
    for i in range(len(s1)):
        if s1[i]!=s2[i]:k+=1
    return k
for i in range(n):
    s.append(input()+input()+input()+input()+input())
r=37
ri,rj=0,0
for i in range(n):
    for j in range(i):
        t=f(s[i],s[j])
        if t<r:
            r=t
            ri=i+1
            rj=j+1
print(rj,ri)
