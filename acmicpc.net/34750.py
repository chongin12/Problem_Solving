n=int(input())
r=0
if n>=1000000:r=20
elif n>=500000:r=15
elif n>=100000:r=10
else:r=5
print(f"{n//100*(r)} {n//100*(100-r)}")