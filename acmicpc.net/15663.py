from itertools import permutations
n,m=map(int,input().split())
l=list(map(int,input().split()))
r=sorted(list(permutations(l,m)))
for i in range(len(r)):
	if i==0 or r[i-1]!=r[i]:print(*r[i])