n=int(input())
res=0
for j in range(n-1, 2, -1):
    for k in range(j-1, 1, -1):
        for w in range(k-1, 0, -1):
            # print(j, k, w)
            res+=1
print(res)

