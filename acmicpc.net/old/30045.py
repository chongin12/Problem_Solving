n=int(input())
r=0
for _ in range(n):
    t=input()
    if t.count("01")>0 or t.count("OI")>0:
        r+=1
print(r)