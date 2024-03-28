l=[]
a=[0 for i in range(1001)]
M=0
r=0
for i in range(10):
    k=int(input())
    l.append(k)
    a[k]+=1
    if M<a[k]:
        M=a[k]
        r=k
print(sum(l)//10)
print(r)
