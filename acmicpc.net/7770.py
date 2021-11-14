n=int(input())-1
r=1
k=1
while 1:
	n-=(k*2+1)**2-(k+1)*k*2
	if n>=0:
		r+=1
		k+=1
	else:break
print(r)