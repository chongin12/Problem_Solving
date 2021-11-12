import math
a,b=map(int,input().split())
g=[list(input()) for _ in range(a)]
for i in range(len(g)):
	for j in range(len(g[i])):
		g[i][j]=ord(g[i][j])-ord('0')
res=-1
if a==1 and b==1:
	t=g[0][0]
	if t==0:
		res=max(res,t)
	elif t==int(math.sqrt(t))**2:
		res=max(res,t)
for w in range(a):
	for k in range(b):
		for i in range(a):
			for j in range(b):
				if i==0 and j==0:
					continue
				for d in range(4):
					s=1
					u=1
					if d==1:
						s=-1
					elif d==2:
						u=-1
					elif d==3:
						s=-1
						u=-1
					x=w
					y=k
					t=-999
					while y>=0 and y<b and x<a and x>=0:
						if t==-999:
							t=g[x][y]
						else:
							t=10*t+g[x][y]
						x+=i*u
						y+=j*s
						if t!=999 and t==int(math.sqrt(t))**2:
							res=max(res,t)
print(res)