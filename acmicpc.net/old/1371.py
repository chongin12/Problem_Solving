a=[0 for i in range(27)]
m=0
while 1:
	try:
		for i in input():
			if i==' ':continue
			t=int(ord(i)-ord('a'))
			a[t]+=1
			if m<a[t]:
				m=a[t]
	except:
		break
for i in range(len(a)):
	if a[i]==m:print(chr(i+ord('a')),end='')