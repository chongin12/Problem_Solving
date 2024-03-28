n=int(input())
i=0
while 1:
	i+=1
	if n==1:break
	elif n%2==1:n=3*n+1
	else:n//=2
print(i)