l=['a','e','i','o','u','A','E','I','O','U']
while 1:
	a=input()
	if a=="#":break
	res=0
	for i in a:
		for j in l:
			if i==j:res+=1
	print(res)