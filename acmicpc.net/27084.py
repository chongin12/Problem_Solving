N=int(input())
dict={}
for a in list(map(int,input().split())):
    if a in dict:
        dict[a]+=1
    else:
        dict[a]=1
res=1
for i in dict.values():
    res*=(i+1)
print((res-1)%(1000000007))