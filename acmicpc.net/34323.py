n,m,s=map(int,input().split())
print(min((100-n)*(m+1)*s//100,m*s))