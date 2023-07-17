M,S,G=map(float,input().split())
A,B=map(float,input().split())
L,R=map(float,input().split())
l=L/A+M/G
r=R/B+M/S
print("friskus" if l<r else "latmask")