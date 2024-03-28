a,b,c=map(int,input().split())
A=(a+b-c)/2
B=a-A
C=b-A
if A<=0 or B<=0 or C<=0:print(-1)
else:
	print(1)
	print(round(A/2,1),round(B/2,1),round(C/2,1))