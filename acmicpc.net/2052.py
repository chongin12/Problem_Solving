s=list("%.250f"%(1/2**int(input())))
for i in range(len(s)-1,-1,-1):
	if s[i]!='0':
		break
	del s[i]
print(''.join(s))