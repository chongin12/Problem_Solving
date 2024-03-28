n=int(input())
l=list(map(int,input().split()))
T,P=map(int,input().split())
c=0
for i in l:
    c+=i//T
    if i%T>0:c+=1
print(c)
print(sum(l)//P, sum(l)%P)