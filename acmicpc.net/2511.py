a=list(map(int,input().split()))
b=list(map(int,input().split()))
A=0
B=0
l=0
for i in range(10):
	if a[i]>b[i]:
		A+=3
		l=1
	elif a[i]<b[i]:
		B+=3
		l=-1
	else:
		A+=1
		B+=1
print(A,B)
if A>B or (A==B and l==1):
	print("A")
elif A==B and l==0:
	print("D")
else:
	print("B")