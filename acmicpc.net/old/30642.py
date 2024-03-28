n=int(input())
a=input()
k=int(input())
if a[0]=='a':
    if k%2==0 and k==n:print(k-1)
    else:print(k//2*2+1)
else:
    if k==1:print(k+1)
    else:print(k//2*2)