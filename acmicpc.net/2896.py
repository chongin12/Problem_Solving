a,b,c=map(float,input().split())
i,j,k=map(float,input().split())
r=min(a/i, b/j, c/k)
print(f"{a-i*r:.5f} {b-j*r:.5f} {c-k*r:.5f}")