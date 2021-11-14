a=input().split()
p=1
k=int(a[0])
for i in range(2,k):
	if k%i==0:
		p=0
		break
k=int(a[1]+a[0])
for i in range(2,k):
	if p==0 or k%i==0:
		p=0
		break
print(f"{'Yes' if p else 'No'}")