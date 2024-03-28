l=[[0,2,0,1],[2,1,3,0],[0,3,2,1],[1,0,1,3]]
d={'A':0,'G':1,'C':2,'T':3}
D=['A','G','C','T']
n=int(input())
s=input()
k=s[-1]
for i in range(n-2,-1,-1):
	k=D[l[d[s[i]]][d[k]]]
print(k)