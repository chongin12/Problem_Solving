r=0
for i in range(8):
	s=input()
	for j in range(len(s)):
		if i%2==0 and j%2==0 and s[j]=='F':r+=1
		elif i%2==1 and j%2==1 and s[j]=='F':r+=1
print(r)