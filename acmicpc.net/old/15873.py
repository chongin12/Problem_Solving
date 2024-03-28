a=input()
if len(a)==3 and a[1]=='0':
	print(int(a[0:2])+int(a[2]))
elif len(a)==3 and a[1]!='0':
	print(int(a[0])+int(a[1:3]))
elif(len(a)==2):
	print(int(a[0])+int(a[1]))
else:
	print(int(a[0:2])+int(a[2:]))