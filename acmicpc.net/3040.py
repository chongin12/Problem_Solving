l=[]
sum=0
for i in range(9):
    a=int(input())
    l.append(a)
    sum+=a
for i in range(9):
    for j in range(i+1, 9, 1):
        if sum-l[i]-l[j] == 100:
            for k in range(9):
                if not(k==i or k==j):
                    print(l[k])