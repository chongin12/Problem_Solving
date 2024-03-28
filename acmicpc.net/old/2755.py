A={"F":0.0,"D-":0.7,"D0":1.0,"D+":1.3,"C-":1.7,"C0":2.0,"C+":2.3,"B-":2.7,"B0":3.0,"B+":3.3,"A-":3.7,"A0":4.0,"A+":4.3}
n=int(input())
s=0
r=0
for i in range(n):
    a,b,c=map(str,input().split())
    s+=int(b)
    r+=int(b)*A[c]
print(f"{r/s+0.0000000001:.2f}")