a=1
for i in input():
	if i=='A' and a!=3:
		a=3-a
	elif i=='B' and a!=1:
		a=5-a
	elif i=='C' and a!=2:
		a=4-a
print(a)