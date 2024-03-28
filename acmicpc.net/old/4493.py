d={"R":"S","S":"P","P":"R"}
for _ in range(int(input())):
	f,s=[0,0]
	for i in range(int(input())):
		a,b=input().split()
		if a==b:
			pass
		elif d[a]==b:
			f+=1
		else:
			s+=1
	if f==s:
		print("TIE")
	elif f>s:
		print("Player 1")
	else:
		print("Player 2")