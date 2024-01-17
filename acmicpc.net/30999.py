n,m=map(int,input().split())
r=0
for _ in range(n):
    a=input().count("O")
    if a>(m//2):r+=1
print(r)