q,w,e,r,t=[0,0,0,0,0]
for _ in range(int(input())):
	a,b=map(int,input().split())
	if a==0 or b==0:t+=1
	elif a>0:
		if b>0:q+=1
		else:r+=1
	else:
		if b>0:w+=1
		else:e+=1
print(f"Q1: {q}\nQ2: {w}\nQ3: {e}\nQ4: {r}\nAXIS: {t}")