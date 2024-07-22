n=int(input())
l=' '.join([str((i-1)%5+1) for i in range(1,11,1)])
for i in range(n):
    s=input()
    if s==l:print(i+1)