m=int(input())
n=int(input())
if m==1 and n==1:print(1)
else:print(m*n-max(0,(m-2)*(n-2)))