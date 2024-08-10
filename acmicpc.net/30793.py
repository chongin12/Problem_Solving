n,m=map(int,input().split())
if n/m<0.2:s="weak"
elif n/m<0.4:s="normal"
elif n/m<0.6:s="strong"
else:s="very strong"
print(s)