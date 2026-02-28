x,k=map(int,input().split())
l=list(map(int,input().split()))
s1=l[:x]
sums1=sum(s1)
cnts1=[0] * 10001
s2=l[x:]
sums2=sum(s2)
cnts2=[0] * 10001
res=0
for i in s1:
    cnts1[i]+=1
for i in s2:
    cnts2[i]+=1
for i in s1:
    res+=len(s2)-cnts2[i]
print(res)