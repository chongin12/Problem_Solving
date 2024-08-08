a=input()
b=input()
for i in range(len(a)):
    print(max(int(a[i]), int(b[i])), end="")
print()