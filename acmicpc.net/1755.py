m,n=map(int,input().split())
l=[
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
]
r=[]
for i in range(m, n+1, 1):
    s=""
    if i < 10 : s+=l[i]
    else:
        s+=l[i//10]
        s+=l[i%10]
    r.append([s, i])
r.sort(key=lambda x: x[0])
for i in range(len(r)):
    if i!=0 and i%10==0:print()
    print(r[i][1], end=' ')