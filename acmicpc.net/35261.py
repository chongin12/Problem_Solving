n=int(input())
s=input()
rr=0
for i in range(n-4):
    k=s[i:i+5]
    r=0
    if k[0]=='e':r+=1
    if k[1]=='a':r+=1
    if k[2]=='g':r+=1
    if k[3]=='l':r+=1
    if k[4]=='e':r+=1
    rr=max(r,rr)
print(5-rr)