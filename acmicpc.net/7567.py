r=0
s=input()
prev=""
for i in s:
    if i!=prev:r+=10
    else:r+=5
    prev=i
print(r)