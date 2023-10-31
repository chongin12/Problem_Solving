n, m, k = map(int,input().split())

print(max(0, n-m*k), max(0, n-m*(k-1)-1))