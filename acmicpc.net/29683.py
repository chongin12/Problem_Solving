n,A=map(int,input().split())
r=0
for i in list(map(int,input().split())):
    r+=i//A
print(r)