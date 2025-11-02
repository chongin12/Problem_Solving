s=input()
for i in s:
    if ord(i)>=97:print(chr((ord(i)-97+13)%26+97), end='')
    elif ord(i)>=65:print(chr((ord(i)-65+13)%26+65), end='')
    else:print(i, end='')
print()