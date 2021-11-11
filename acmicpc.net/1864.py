a={'-':0,'\\':1,'(':2,'@':3,'?':4,'>':5,'&':6,'%':7,'/':-1}
while True:
	b=input()
	if b=="#":
		break
	r=0
	j=1
	for i in range(len(b)-1,-1,-1):
		r+=a[b[i]]*j
		j*=8
	print(r)