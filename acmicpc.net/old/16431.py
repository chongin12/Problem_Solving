a1,a2=map(int,input().split())
b1,b2=map(int,input().split())
c1,c2=map(int,input().split())
a=max(abs(a1-c1),abs(a2-c2))
b=abs(b1-c1)+abs(b2-c2)
if a==b:
	print("tie")
elif(a<b):
	print("bessie")
else:
	print("daisy")