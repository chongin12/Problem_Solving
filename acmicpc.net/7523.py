n = int(input())
for i in range(n):
    a,b=map(int,input().split())
    print(f"Scenario #{i+1}:\n{(a+b)*(b-a+1)//2}\n")
