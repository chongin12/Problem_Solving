d={'R':'S','S':'P','P':'R'}
q,w,e,r=input().split()
t=0
if (d[q]==e and d[q]==r) or (d[w]==e and d[w]==r):
	print("MS")
elif (d[e]==q and d[e]==w) or (d[r]==q and d[r]==w):
	print("TK")
else:
	print("?")