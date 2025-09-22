a,b=map(int,input().split())
for i in range(abs(a-b)):
    print("1",end='')
for i in range(min(a,b)):
    print("2",end='')
print()