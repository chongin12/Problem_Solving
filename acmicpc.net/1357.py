a,b=input().split()
c=f"{int(''.join(reversed(a)))+int(''.join(reversed(b)))}"
print(int(''.join(reversed(c))))