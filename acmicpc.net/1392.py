n,q=map(int,input().split())
l=[0 for i in range(101)]
l[0]=int(input())-1
for i in range(1,n):
	l[i]=int(input())+l[i-1]
for i in range(q):
	a=int(input())
	for j in range(len(l)):
		if a<=l[j]:
			print(j+1)
			break