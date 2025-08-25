s=input()
N=len(s)
R,C=0,0
for i in range(N,0,-1):
    if N%i==0 and i<=N//i:
        R=i
        C=N//i
        break

res=""
for i in range(R):
    for j in range(C):
        res+=s[j*R+i]
print(res)