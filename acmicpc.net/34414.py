n=int(input())
a=1000
for i in range(n):
    a=min(a,int(input()))
if a<48:print("False")
else:print("True")