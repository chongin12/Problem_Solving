n=int(input())
f=int(input())
for i in range(n-n%100,n-n%100+100):
	if i%f==0:
		print(f"{i%100:02d}")
		break