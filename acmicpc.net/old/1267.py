a=int(input())
r1=0
r2=0
b=list(map(int, input().split()))
for i in range(a):
	r1+=10*(b[i]//30+1)
	r2+=15*(b[i]//60+1)
if r1==min(r1,r2):
	print("Y ", end='')
if r2==min(r1,r2):
	print("M ", end='')
print(min(r1, r2))