n=int(input())
l=list(map(int,input().split()))
if len(set(l))==len(l):print(1)
else:print(0)