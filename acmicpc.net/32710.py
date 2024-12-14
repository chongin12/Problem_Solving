n=int(input())
flag=False
if n==1:flag=True
for i in range(2, 10):
    if n%i==0 and n//i<=9:flag=True
if flag:print("1")
else:print("0")