def f(n):
	r=0
	for i in n:
		r+=int(i)
	if r>9:
		return f(f"{r}")
	return r
while 1:
	a=input()
	if a=="0":break
	print(f(a))