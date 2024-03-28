n=int(input())
p=int(input())
r=p
if n>=20:r=min(r,p//4*3)
if n>=15:r=min(r,p-2000)
if n>=10:r=min(r,p//10*9)
if n>=5:r=min(r,p-500)
print(max(r,0))