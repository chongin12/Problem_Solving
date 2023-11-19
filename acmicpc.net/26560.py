n=int(input())
for _ in range(n):
    a=input()
    print(f"{a}{'.' if a[-1]!='.' else ''}")