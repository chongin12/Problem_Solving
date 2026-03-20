n,m=map(int,input().split())
for i in range(n):
    if input().count('A')!=1:
        print("No")
        exit(0)
print("Yes")