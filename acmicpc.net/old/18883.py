a,b=map(int,input().split())
s=''
for i in range(a):
	for j in range(b):
		s+=str(i*b+j+1)
		if j!=b-1:s+=' '
		else:s+='\n'
print(s,end='')