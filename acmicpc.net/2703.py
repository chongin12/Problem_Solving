t=int(input())
for _ in range(t):
    s=input()
    d=input()
    for i in s:
        if i==' ':print(' ', end='')
        else:print(d[ord(i)-ord('A')], end='')
    print()