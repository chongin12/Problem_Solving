for i in range(101):
    s=input()
    if s=="Was it a cat I saw?":break
    for j in range(0, len(s), i+2):
        print(s[j], end='')
    print()