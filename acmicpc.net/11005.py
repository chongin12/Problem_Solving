a,b=map(int,input().split())
d=[str(i) for i in range(10)]+[chr(i) for i in range(65, 91)]
s=""
while a>0:
    s+=d[a%b]
    a//=b
print(s[::-1])
