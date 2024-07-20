b,c,d=map(int,input().split())
A=sorted(list(map(int,input().split())))[::-1]
B=sorted(list(map(int,input().split())))[::-1]
C=sorted(list(map(int,input().split())))[::-1]
print(sum(A)+sum(B)+sum(C))
for i in range(min(b,c,d)):
    A[i]=A[i]//10*9
    B[i]=B[i]//10*9
    C[i]=C[i]//10*9
print(sum(A)+sum(B)+sum(C))