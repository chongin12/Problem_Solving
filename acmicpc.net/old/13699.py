t=[0]*50
t[0]=1
t[1]=1
n=int(input())
for i in range(2, n+1, 1):
    for j in range(i):
        t[i]+=t[j]*t[i-1-j]
print(t[n])