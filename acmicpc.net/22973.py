a=abs(int(input()))
print(0 if a==0 else -1 if a%2==0 else len(bin(a)[2:]))