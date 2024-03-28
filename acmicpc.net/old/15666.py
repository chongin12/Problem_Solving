from itertools import combinations_with_replacement
n,m=map(int,input().split())
l=sorted(list(map(int,input().split())))
r=sorted(list(combinations_with_replacement(l,m)))
for i in range(len(r)):
	if i==0 or r[i-1]!=r[i]:print(*r[i])