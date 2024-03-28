a=input()
b=input()
d=[0 for i in range(26)]
for i in a:
	d[ord(i)-97]+=1
for i in b:
	d[ord(i)-97]-=1
r=0
for i in d:
	if i<0:r+=-i
	else:r+=i
print(r)