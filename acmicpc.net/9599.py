n=int(input())
for i in range(n):
    print(f"Case #{i+1}: {max(list(map(int,input().split())))}")