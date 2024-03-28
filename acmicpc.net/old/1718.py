p=input()
c=input()
n=0
for i in p:
	if i==' ':print(" ",end='')
	else:print(chr((ord(i)-ord(c[n])+25)%26+97),end='')
	n=(n+1)%len(c)